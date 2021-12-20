#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class	Contact
{
	private :
		size_t			index;
		std::string		fstName,
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
	public :
		Contact(void);
		Contact(int index, const std::string &fstName, const std::string &lstName,
					const std::string &nickname, const std::string &login,
					const std::string &postAddr, const std::string &emailAddr,
					const std::string &phoneNum, const std::string &birthday,
					const std::string &favMeal, const std::string &underwearColor,
					const std::string &darkestSecret);

		size_t			getIndex(void);
		std::string		getFstName(void);
		std::string		getLstName(void);
		std::string		getNickname(void);
		std::string		getLogin(void);
		std::string		getPostAddr(void);
		std::string		getEmailAddr(void);
		std::string		getPhoneNum(void);
		std::string		getBirthday(void);
		std::string		getFavMeal(void);
		std::string		getUnderwearColor(void);
		std::string		getDarkestSecret(void);

		void			setIndex(size_t index);
		void			setFstName(const std::string &fstname);
		void			setLstName(const std::string &lstName);
		void			setNickname(const std::string &nickname);
		void			setLogin(const std::string &login);
		void			setPostAddr(const std::string &postAddr);
		void			setEmailAddr(const std::string &emailAddr);
		void			setPhoneNum(const std::string &phoneNum);
		void			setBirthday(const std::string &birthday);
		void			setFavMeal(const std::string &favMeal);
		void			setUnderwearColor(const std::string &underwearColor);
		void			setDarkestSecret(const std::string &darkestSecret);
};

#endif
