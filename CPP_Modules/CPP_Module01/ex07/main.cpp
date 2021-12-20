#include <iostream>
#include <fstream>
#include <cstring>

int		main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "invalid count of params" << std::endl;
	else if (!strlen(argv[2]) || !strlen(argv[3]))
		std::cout << "some string is empty" << std::endl;
	else
	{
		std::ifstream	inFile;
		
		inFile.open((argv[1]), std::ifstream::in);
		if (!inFile.is_open())
		{
			std::cout << "can't open file : " << argv[1] << std::endl;
			return (0);
		}
		std::ofstream	outFile;
		
		outFile.open((std::string(argv[1]) + ".replace"),
			std::ofstream::out | std::ofstream::trunc);
		if (!inFile.is_open())
		{
			std::cout << "can't create .replace file" << std::endl;
			return (0);
		}
		while (!inFile.eof())
		{
			std::string	str;
			getline(inFile, str);
			while (str.find(argv[2]) != std::string::npos)
				str.replace(str.find(argv[2]), strlen(argv[2]), argv[3]);
			if (!inFile.eof())
				outFile << str << std::endl;
		}
		inFile.close();
		outFile.close();
	}
	return (0);
}
