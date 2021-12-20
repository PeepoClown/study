#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
	: array(nullptr), arraySize(0)
{ }

template <typename T>
Array<T>::~Array()
{
	delete [] this->array;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		this->array[i] = static_cast<T>(0);
	this->arraySize = static_cast<std::size_t>(n);
}

template <typename T>
Array<T>::Array(const Array<T> &array)
{
	*this = array;
}

template <typename T>
Array<T>&		Array<T>::operator= (const Array<T>& array)
{
	if (this->array != nullptr)
		delete [] this->array;

	this->arraySize = array.arraySize;
	this->array = new T[array.arraySize];

	for (std::size_t i = 0; i < array.arraySize; i++)
		this->array[i] = array[i];

	return (*this);
}

template <typename T>
T&			Array<T>::operator[] (const int &index)
{
	if (index < 0 || index >= static_cast<int>(this->arraySize))
		throw InvalidIndexException("invalid index");
	return (this->array[index]);
}

template <typename T>
const T&	Array<T>::operator[] (const int &index) const
{
	if (index < 0 || index >= static_cast<int>(this->arraySize))
		throw InvalidIndexException("invalid index");
	return (this->array[index]);
}

template <typename T>
std::size_t	Array<T>::size(void) const
{
	return (this->arraySize);
}

template <typename T>
std::ostream&	operator<< (std::ostream& out, const Array<T> &array)
{
	out << "array : " << std::endl;
	std::size_t i = 0;
	for ( ; i < array.size(); i++)
	{
		out << std::setw(7) << array[i];
		if ((i + 1) % 10 == 0)
			out << std::endl;
		else
			out << " ";
	}
	out << std::endl;
	return (out);
}

template <typename T>
Array<T>::InvalidIndexException::InvalidIndexException(void)
	: errorMsg("")
{ }

template <typename T>
Array<T>::InvalidIndexException::~InvalidIndexException() _NOEXCEPT
{ }

template <typename T>
Array<T>::InvalidIndexException::InvalidIndexException(const std::string &errorMsg)
	: errorMsg(errorMsg)
{ }

template <typename T>
Array<T>::InvalidIndexException::InvalidIndexException(const InvalidIndexException
	&invalidIndexException)
{
	*this = invalidIndexException;
}

template <typename T>
typename Array<T>::InvalidIndexException&	Array<T>::InvalidIndexException::operator=
	(const Array<T>::InvalidIndexException &invalidIndexException)
{
	this->errorMsg = invalidIndexException.errorMsg;
	return (*this);
}

template <typename T>
const char*	Array<T>::InvalidIndexException::what(void) const _NOEXCEPT
{
	return (this->errorMsg.c_str());
}

#endif
