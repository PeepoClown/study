#include "Contact.hpp"
#include <iostream>
#include <cstring>
#include <iomanip>

void	typeContact(int curr_id, Contact *contact)
{
	std::string fstName,
				lstName,
				nickname,
				login,
				postAddr,
				emailAddr,
				phoneNum,
				birthday,
				favMeal,
				underwearColor,
				darkestSecret;

	std::cout << "first name : ";
	std::cin >> fstName;
	std::cout << "last name : ";
	std::cin >> lstName;
	std::cout << "nickname : ";
	std::cin >> nickname;
	std::cout << "login : ";
	std::cin >> login;
	std::cout << "postal address : ";
	std::cin >> postAddr;
	std::cout << "email address : ";
	std::cin >> emailAddr;
	std::cout << "phone number : ";
	std::cin >> phoneNum;
	std::cout << "birthday date : ";
	std::cin >> birthday;
	std::cout << "favorite meal : ";
	std::cin >> favMeal;
	std::cout << "underwear color : ";
	std::cin >> underwearColor;
	std::cout << "darkest secret : ";
	std::cin >> darkestSecret;

	contact->setIndex(curr_id);
	contact->setFstName(fstName);
	contact->setLstName(lstName);
	contact->setNickname(nickname);
	contact->setLogin(login);
	contact->setPostAddr(postAddr);
	contact->setEmailAddr(emailAddr);
	contact->setPhoneNum(phoneNum);
	contact->setBirthday(birthday);
	contact->setFavMeal(favMeal);
	contact->setUnderwearColor(underwearColor);
	contact->setDarkestSecret(darkestSecret);
}

std::string	modifyIfLong(std::string str)
{
	std::string	modifiedStr;

	if (str.length() <= 10)
		return (str);
	modifiedStr = str.substr(0, 9);
	modifiedStr.append(".");
	return (modifiedStr);
}

int		main()
{
	Contact		pbook[8];
	size_t		curr_id = 0;

	while (true)
	{
		std::string	cmd;
		std::cin >> cmd;
		if (!strcmp(cmd.c_str(), "EXIT"))
			break ;
		else if (!strcmp(cmd.c_str(), "ADD"))
		{
			if (curr_id > 7)
			{
				std::cout << "phonebook do not store more than 8 contacts" << std::endl;
				continue ;
			}
			typeContact(curr_id, &pbook[curr_id]);
			curr_id++;
		}
		else if (!strcmp(cmd.c_str(), "SEARCH"))
		{
			std::cout << std::right << std::setw(10) << "index" << "|" << std::setw(10)
				<< "first name" << "|" << std::setw(10) << "last name" << "|"
				<< std::setw(10) << "nickname" << std::endl;
			if (curr_id != 0)
			{
				int	i = 0;
				while (i < (int)curr_id)
				{
					std::string	fstName,
								lstName,
								nickname;
					fstName = modifyIfLong(pbook[i].getFstName());
					lstName = modifyIfLong(pbook[i].getLstName());
					nickname = modifyIfLong(pbook[i].getNickname());
					std::cout << std::right << std::setw(10) << pbook[i].getIndex() + 1
						<< "|" << std::setw(10) << fstName << "|" << std::setw(10)
						<< lstName << "|" << std::setw(10) << nickname << std::endl;
					i++;
				}
			}
			int	id;
			std::cout << "type id : ";
			std::cin >> id;
			if (id > 0 && id - 1 < (int)curr_id)
			{
				std::cout << "first name : " << pbook[id - 1].getFstName() << std::endl;
				std::cout << "last name : " << pbook[id - 1].getLstName() << std::endl;
				std::cout << "nickname : " << pbook[id - 1].getNickname() << std::endl;
				std::cout << "login : " << pbook[id - 1].getLogin() << std::endl;
				std::cout << "postal address : " << pbook[id - 1].getPostAddr() << std::endl;
				std::cout << "email address : " << pbook[id - 1].getEmailAddr() << std::endl;
				std::cout << "phone number : " << pbook[id - 1].getPhoneNum() << std::endl;
				std::cout << "birthday date : " << pbook[id - 1].getBirthday() << std::endl;
				std::cout << "favorite meal : " << pbook[id - 1].getFavMeal() << std::endl;
				std::cout << "underwear color : " << pbook[id - 1].getUnderwearColor() << std::endl;
				std::cout << "darkest secret : " << pbook[id - 1].getDarkestSecret() << std::endl;

			}
			else
			{
				std::cout << "invalid id" << std::endl;
				continue ;
			}
		}
		else
			continue ;
	}
	return (0);
}
