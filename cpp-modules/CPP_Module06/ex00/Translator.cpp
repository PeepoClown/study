#include "Translator.hpp"

Translator::Translator(void)
	: type(NOTATYPE), char_value('\0'), int_value(0),
	float_value(0.0f), double_value(0.0)
{ }

Translator::~Translator()
{ }

bool	Translator::isChar(const std::string &literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return (true);
	return (false);
}

bool	Translator::isInt(const std::string &literal)
{
	if (literal.length() < 1)
		return (false);

	std::size_t	pos = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;

	if (pos == 1 && literal.length() < 2)
		return (false);
	while (pos < literal.length())
	{
		if (!std::isdigit(literal[pos]))
			break ;
		pos++;
	}
	if (pos != literal.length())
		return (false);
	return (true);
}

bool	Translator::isFloat(const std::string &literal)
{
	if (literal == "nanf" || literal == "inff" || literal == "+inff"
		|| literal == "-inff")
		return (true);
	if (literal.length() < 3)
		return (false);
	
	std::size_t	pos = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;

	if (pos == 1 && literal.length() < 4)
		return (false);
	while (pos < literal.length())
	{
		if (!std::isdigit(literal[pos]) && literal[pos] != 'f' &&
			literal[pos] != '.')
			break ;
		pos++;
	}
	if (pos != literal.length())
		return (false);
	if (literal.find_first_of('f') == std::string::npos ||
		literal.find_first_of('f') != literal.find_last_of('f') ||
		literal.find_first_of('f') != literal.length() - (std::size_t)1)
		return (false);
	if (literal.find_first_of('.') == std::string::npos ||
		literal.find_first_of('.') != literal.find_last_of('.') ||
		literal.find_first_of('.') == literal.length() - (std::size_t)1)
		return (false);
	return (true);
}

bool	Translator::isDouble(const std::string &literal)
{
	if (literal == "nan" || literal == "inf" || literal == "+inf"
		|| literal == "-inf")
		return (true);
	if (literal.length() < 2)
		return (false);
	
	std::size_t	pos = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;

	if (pos == 1 && literal.length() < 3)
		return (false);
	while (pos < literal.length())
	{
		if (!std::isdigit(literal[pos]) && literal[pos] != '.')
			break ;
		pos++;
	}
	if (pos != literal.length())
		return (false);
	if (literal.find_first_of('.') == std::string::npos ||
		literal.find_first_of('.') != literal.find_last_of('.'))
		return (false);
	return (true);
}

Translator::Translator(const std::string &literal)
	: char_value('\0'), int_value(0), float_value(0.0f), double_value(0.0)
{
	Types resType;

	if (isChar(literal))
		resType = CHAR;
	else if (isInt(literal))
		resType = INT;
	else if (isFloat(literal))
		resType = FLOAT;
	else if (isDouble(literal))
		resType = DOUBLE;
	else
		resType = NOTATYPE;

	if (resType == CHAR)
		this->char_value = literal[0];
	else if (resType == INT)
	{
		char *p;
		long l_value = strtol(literal.c_str(), &p, 10);
		errno = 0;

		if (errno == ERANGE)
			resType = OVERFLOW_;
		else if (l_value > INT_MAX || l_value < INT_MIN)
			resType = OVERFLOW_;
		else
			this->int_value = l_value;
	}
	else if (resType == FLOAT)
	{
		char *p;
		float f_value = strtof(literal.c_str(), &p);

		if (literal == "nanf" || literal == "inff" || literal == "+inff"
			|| literal == "-inff")
			this->float_value = f_value;
		else
		{
			if (f_value == HUGE_VALF)
				resType = OVERFLOW_;
			else
				this->float_value = f_value;
		}
	}
	else if (resType == DOUBLE)
	{
		char *p;
		double d_value = strtod(literal.c_str(), &p);

		if (literal == "nan" || literal == "inf" || literal == "+inf"
			|| literal == "-inf")
			this->double_value = d_value;
		else
		{
			if (d_value == HUGE_VAL)
				resType = OVERFLOW_;
			else
				this->double_value = d_value;
		}
	}

	this->type = resType;
}

Translator::Translator(const Translator &translator)
{
	*this = translator;
}

Translator&	Translator::operator= (const Translator &translator)
{
	this->type = translator.type;
	this->char_value = translator.char_value;
	this->int_value = translator.int_value;
	this->float_value = translator.float_value;
	this->double_value = translator.double_value;
	return (*this);
}

std::string	Translator::getType(void) const
{
	if (this->type == CHAR)
		return ("char");
	else if (this->type == INT)
		return ("int");
	else if (this->type == FLOAT)
		return ("float");
	else if (this->type == DOUBLE)
		return ("double");
	else if (this->type == OVERFLOW_)
		return ("error, passed value is overflow");
	else
		return ("error, passed value don't become to types : char, int, float, double");
}

void	Translator::print_char(void)
{
	std::cout << "char : ";
	if (this->type == OVERFLOW_ || this->type == NOTATYPE)
		std::cout << "impossible" << std::endl;
	else if (this->type == FLOAT && (isinf(this->float_value) || isnan(this->float_value)))
		std::cout << "impossible" << std::endl;
	else if (this->type == DOUBLE && (isinf(this->double_value) || isnan(this->double_value)))
		std::cout << "impossible" << std::endl;
	else if (this->type == CHAR)
		std::cout << this->char_value << std::endl;
	else
	{
		int cast_value = 0;
		if (this->type == INT)
			cast_value = this->int_value;
		else if (this->type == FLOAT)
			cast_value = static_cast<int>(this->float_value);
		else if (this->type == DOUBLE)
			cast_value = static_cast<int>(this->double_value);

		if (cast_value > 127 || cast_value < -128)
			std::cout << "impossible" << std::endl;
		else if (cast_value == 127 || cast_value < 32)
			std::cout << "Non displayable" << std::endl;
		else
		{
			this->char_value = static_cast<char>(cast_value);
			std::cout << this->char_value << std::endl;
		}
	}
}

void	Translator::print_int(void)
{
	std::cout << "int : ";
	if (this->type == OVERFLOW_ || this->type == NOTATYPE)
		std::cout << "impossible" << std::endl;
	else if (this->type == FLOAT && (isinf(this->float_value) || isnan(this->float_value)))
		std::cout << "impossible" << std::endl;
	else if (this->type == DOUBLE && (isinf(this->double_value) || isnan(this->double_value)))
		std::cout << "impossible" << std::endl;
	else if (this->type == INT)
		std::cout << this->int_value << std::endl;
	else
	{
		int cast_value = 0;
		if (this->type == CHAR)
			cast_value = static_cast<int>(this->char_value);
		else if (this->type == FLOAT)
		{
			if (this->float_value > static_cast<float>(INT_MAX)
				|| this->float_value < static_cast<float>(INT_MIN))
			{
				std::cout << "impossible" << std::endl;
				return ;
			}
			cast_value = static_cast<int>(this->float_value);
		}
		else if (this->type == DOUBLE)
		{
			if (this->double_value > static_cast<double>(INT_MAX)
				|| this->double_value < static_cast<double>(INT_MIN))
			{
				std::cout << "impossible" << std::endl;
				return ;
			}
			cast_value = static_cast<int>(this->double_value);
		}
		this->int_value = cast_value;
		std::cout << this->int_value << std::endl;
	}
}

void	Translator::print_float(void)
{
	std::cout << "float : ";
	if (this->type == OVERFLOW_ || this->type == NOTATYPE)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	else if (this->type == FLOAT)
		std::cout << this->float_value;
	else
	{
		float cast_value = 0.0f;

		if (this->type == CHAR)
			cast_value = static_cast<float>(this->char_value);
		else if (this->type == INT)
			cast_value = static_cast<float>(this->int_value);
		else if (this->type == DOUBLE)
		{
			if (this->double_value > static_cast<double>(std::numeric_limits<float>::max())
				|| this->double_value < static_cast<double>(std::numeric_limits<float>::max() * -1))
			{
				std::cout << "impossible" << std::endl;
				return ;
			}
			cast_value = static_cast<float>(this->double_value);
		}
		this->float_value = cast_value;
		std::cout << this->float_value;
	}
	std::cout << "f" << std::endl;
}

void	Translator::print_double(void)
{
	std::cout << "double : ";
	if (this->type == OVERFLOW_ || this->type == NOTATYPE)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	else if (this->type == DOUBLE)
		std::cout << this->double_value << std::endl;
	else
	{
		double cast_value = 0.0;

		if (this->type == CHAR)
			cast_value = static_cast<double>(this->char_value);
		else if (this->type == INT)
			cast_value = static_cast<double>(this->int_value);
		else if (this->type == FLOAT)
			cast_value = static_cast<double>(this->float_value);
		this->double_value = cast_value;
		std::cout << this->double_value << std::endl;
	}
}
