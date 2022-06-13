# Васев Д.А. - БСБО-01-18
# Лабораторная работа 1

## Задание
1. Необходимо разработать переборщик паролей для формы в задании Bruteforce на сайте dvwa.local (Можно использовать официальный ресурс или виртуальную машину Web Security Dojo)
2. Проанализировать код и сделать кодревью, указав слабые места. 
```php
<?php
if( isset( $_GET[ 'Login' ] ) ) {
	// Get username
	$user = $_GET[ 'username' ];
	// Get password
	$pass = $_GET[ 'password' ];
	$pass = md5( $pass );
	// Check the database
	$query  = "SELECT * FROM `users` WHERE user = '$user' AND password = '$pass';";
	$result = mysqli_query($GLOBALS["___mysqli_ston"],  $query ) or die( '<pre>' . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)) . '</pre>' );
	if( $result && mysqli_num_rows( $result ) == 1 ) {
		// Get users details
		$row    = mysqli_fetch_assoc( $result );
		$avatar = $row["avatar"];
		// Login successful
		$html .= "<p>Welcome to the password protected area {$user}</p>";
		$html .= "<img src=\"{$avatar}\" />";
	}
	else {
		// Login failed
		$html .= "<pre><br />Username and/or password incorrect.</pre>";
	}
	((is_null($___mysqli_res = mysqli_close($GLOBALS["___mysqli_ston"]))) ? false : $___mysqli_res);
}
?>
```
3.Разработать свою систему авторизации на любом языке, исключающий взможность подбора паролей разработнным переборщиком паролей в задании 1. Возможно исправление авторизации из dvwa.local
Требования к системе авторизации: 
Система авторизации должна использовать запросы GET с параметрами, аналогичными из задания bruteforce dvwa
`dvwa.local/vulnerabilities/brute/?username=USER&password=PASS&user_token=TOKEN&Login=Login`

## Ход работы
### 1. Переборщик паролей для формы в задании Bruteforce на сайте dvwa.local
Переборшик паролей исользует 10 самых частых логинов(немного, но не так долго длится перебор) и 10000 паролей,
взятых с репозитория https://github.com/danielmiessler/SecLists/blob/master/Passwords/Common-Credentials/10k-most-common.txt. В случае успеха, программа выводит логин + пароль, иначе пишет о неудачном поиске.
![success](https://i.ibb.co/Dt9H94X/1.png)

### 2. Анализ кода
`CWE-598`: Использование метода запроса GET с чувствительными строками запроса
```
$user = $_GET[ 'username' ];
$pass = $_GET[ 'password' ];
```

`CWE-327`: Использование устаревшего криптографического алгоритма MD5
`$pass = md5( $pass );`

`CWE-89`: Неправильная нейтрализация специальных элементов, используемых в команде SQL
`$query  = "SELECT * FROM 'users' WHERE user = '$user' AND password = '$pass';";`

`CWE-307`: Неправильное ограничение или отсутствия чрезмерных попыток аутентификации
```
$result = mysqli_query($GLOBALS["___mysqli_ston"],  $query ) or die( '<pre>' . ((is_object($GLOBALS["___mysqli_ston"])) ? mysqli_error($GLOBALS["___mysqli_ston"]) : (($___mysqli_res = mysqli_connect_error()) ? $___mysqli_res : false)) . '</pre>' );
```

### 3. Авторизация, с защитой от полного перебора
В качетсве защиты от данного способа получения данных учетной записи, я выбрал метод ограничения числа неудачных попыток на логин, с последующим таймаутом.