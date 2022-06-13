#include "Contact.hpp"

Contact::Contact()
	:	index(0), fstName(""), lstName(""), nickname(""), login(""), postAddr(""), emailAddr(""),
		phoneNum(""), birthday(""), favMeal(""), underwearColor(""), darkestSecret("")
{ }

Contact::Contact(int index, const std::string &fstName, const std::string &lstName,
					const std::string &nickname, const std::string &login,
					const std::string &postAddr, const std::string &emailAddr,
					const std::string &phoneNum, const std::string &birthday,
					const std::string &favMeal, const std::string &underwearColor,
					const std::string &darkestSecret)
	:	index(index), fstName(fstName), lstName(lstName), nickname(nickname), login(login),
		postAddr(postAddr), emailAddr(emailAddr), phoneNum(phoneNum), birthday(birthday),
		favMeal(favMeal), underwearColor(underwearColor), darkestSecret(darkestSecret)
{ }

size_t		Contact::getIndex(void)
{
	return (this->index);
}

std::string	Contact::getFstName(void)
{
	return (this->fstName);
}

std::string	Contact::getLstName(void)
{
	return (this->lstName);
}

std::string	Contact::getNickname(void)
{
	return (this->nickname);
}

std::string	Contact::getLogin(void)
{
	return (this->login);
}

std::string	Contact::getPostAddr(void)
{
	return (this->postAddr);
}

std::string	Contact::getEmailAddr(void)
{
	return (this->emailAddr);
}

std::string	Contact::getPhoneNum(void)
{
	return (this->phoneNum);
}

std::string	Contact::getBirthday(void)
{
	return (this->birthday);
}

std::string	Contact::getFavMeal(void)
{
	return (this->favMeal);
}

std::string	Contact::getUnderwearColor(void)
{
	return (this->underwearColor);
}

std::string	Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}

void	Contact::setIndex(size_t index)
{
	this->index = index;
}

void	Contact::setFstName(const std::string &fstName)
{
	this->fstName = fstName;
}

void	Contact::setLstName(const std::string &lstName)
{
	this->lstName = lstName;
}
void	Contact::setNickname(const std::string &nickname)
{
	this->nickname = nickname;
}

void	Contact::setLogin(const std::string &login)
{
	this->login = login;
}

void	Contact::setPostAddr(const std::string &postAddr)
{
	this->postAddr = postAddr;
}

void	Contact::setEmailAddr(const std::string &emailAddr)
{
	this->emailAddr = emailAddr;
}

void	Contact::setPhoneNum(const std::string &phoneNum)
{
	this->phoneNum = phoneNum;
}

void	Contact::setBirthday(const std::string &birthday)
{
	this->birthday = birthday;
}

void	Contact::setFavMeal(const std::string &favMeal)
{
	this->favMeal = favMeal;
}

void	Contact::setUnderwearColor(const std::string &underwearColor)
{
	this->underwearColor = underwearColor;
}

void	Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->darkestSecret = darkestSecret;
}
