# Васев Д.А. - БСБО-01-18
# Лабораторная работа 2

## Задание
- Необходимо найти участок кода, содержащий инъекцию SQL кода в задании Blind Sql Injection на сайте dvwa.local с использованием статического анализатора кода (Можно использовать официальный ресурс или виртуальную машину Web Security Dojo)
- Проанализировать код и сделать кодревью, указав слабые места
```java
<?php

if( isset( $_GET[ 'Submit' ] ) ) {
	// Get input
	$id = $_GET[ 'id' ];

	// Check database
	$getid  = "SELECT first_name, last_name FROM users WHERE user_id = '$id';";
	$result = mysqli_query($GLOBALS["___mysqli_ston"],  $getid ); // Removed 'or die' to suppress mysql errors

	// Get results
	$num = @mysqli_num_rows( $result ); // The '@' character suppresses errors
	if( $num > 0 ) {
		// Feedback for end user
		$html .= '<pre>User ID exists in the database.</pre>';
	}
	else {
		// User wasn't found, so the page wasn't!
		header( $_SERVER[ 'SERVER_PROTOCOL' ] . ' 404 Not Found' );

		// Feedback for end user
		$html .= '<pre>User ID is MISSING from the database.</pre>';
	}

	((is_null($___mysqli_res = mysqli_close($GLOBALS["___mysqli_ston"]))) ? false : $___mysqli_res);
}

?>
```
- Разработать свою систему вывода информации об объекте на любом языке, исключающий взможность инъекции SQL кода. Возможно исправление участка кода из dvwa.local

## Ход работы
### 1. Анализ кода на sql инъекцию
![sonar](https://i.ibb.co/fr1nQnN/1.png)

### 2. Код-ревью
В коде видна работа с интерфейсом для sql запросов, и работа ведется с 'голым' sql.
Недостаток этого в том, что любой человек может контроллировать ввод запроса, оборвав
его символом ' и после написал sql инструкции, что может иметь возможность инъекции SQL.
Пример: `?id=${последовательность символов}' ${SQL запрос}`

### 3. Исправление участка кода из dvwa.local
Для исправления описанной проблемы, я собираюсь использовать подготавливаемые запросы,
проекранировать и отформатировать строки запроса, и добавть проверку на 'особые символы', которые
по моему мнению, не имеют место в поле индентификатора.
```java
<?php

if( isset( $_GET[ 'Submit' ]) ) {

    $id = $_GET[ 'id' ];

    if (!preg_match( '/[\s\'#]/', $input )) {
        $query = $db->prepare( 'SELECT first_name, last_name FROM users WHERE user_id = (:id) LIMIT 1;' );
        $query->bindParam( ':id', mysqli_real_escape_string($GLOBALS["___mysqli_ston"],  $id ) );
        $query->execute();

        if( $num > 0 ) {
        	$html .= '<pre>User ID exists in the database.</pre>';
        } else {
            header( $_SERVER[ 'SERVER_PROTOCOL' ] . ' 404 Not Found' );
        	$html .= '<pre>User ID is MISSING from the database.</pre>';
        }
    }

}

?>
```

### Результат
![sonar_fix](https://i.ibb.co/5W9NgCK/2.png)