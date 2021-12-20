#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

template <typename T>
class	Array
{
	private :
		T			*array;
		std::size_t	arraySize;
	private :
		class	InvalidIndexException : public std::exception
		{
			private :
				std::string	errorMsg;
			public :
				InvalidIndexException(void);
				virtual ~InvalidIndexException() _NOEXCEPT;
				explicit InvalidIndexException(const std::string &errorMsg);
				InvalidIndexException(const InvalidIndexException &invalidIndexException);

				InvalidIndexException&	operator= (const InvalidIndexException &invalidIndexException);

				const char*	what(void) const _NOEXCEPT;
		};
	public :
		Array(void);
		~Array();
		explicit Array(unsigned int n);
		Array(const Array<T> &array);

		Array&		operator= (const Array& array);
		T&			operator[] (const int &index);
		const T&	operator[] (const int &index) const;

		std::size_t	size(void) const;
};

template <typename T>
std::ostream&	operator<< (std::ostream& out, const Array<T> &array);

#endif
