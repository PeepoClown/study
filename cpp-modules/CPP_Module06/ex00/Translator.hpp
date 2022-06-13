#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include <cerrno>
#include <climits>
#include <math.h>

class	Translator
{
	private :
		enum	Types
		{
			CHAR = 0,
			INT,
			FLOAT,
			DOUBLE,
			NOTATYPE,
			OVERFLOW_
		};
	private :
		Types	type;
		char	char_value;
		int		int_value;
		float	float_value;
		double	double_value;

		bool	isChar(const std::string &literal);
		bool	isInt(const std::string &literal);
		bool	isFloat(const std::string &literal);
		bool	isDouble(const std::string &literal);
	public :
		Translator(void);
		~Translator();
		Translator(const std::string &literal);
		Translator(const Translator &translator);

		Translator&	operator= (const Translator &translator);

		std::string	getType(void) const;

		void	print_char(void);
		void	print_int(void);
		void	print_float(void);
		void	print_double(void);
};

#endif
