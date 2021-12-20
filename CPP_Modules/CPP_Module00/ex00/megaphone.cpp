#include <iostream>
#include <string>

bool		isLower(char ch)
{
	return (ch >= 97 && ch <= 123);
}

std::string	getUppStr(const std::string &str)
{
	std::string strUpp;
	int			i = 0;

	while (str[i])
	{
		strUpp += isLower(str[i]) ? str[i] - 32 : str[i];
		i++;
	}
	return (strUpp);
}

int		main(int argc, char **argv)
{
	int		i = 1;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (i < argc)
		{
			std::string current(argv[i]);
			std::cout << getUppStr(current);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
