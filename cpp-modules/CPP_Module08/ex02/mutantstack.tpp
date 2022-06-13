#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
	: std::stack<T>()
{ }

template <typename T>
MutantStack<T>::~MutantStack()
{ }

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &mutantStack)
{
	*this = mutantStack;
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator= (const MutantStack<T> &mutantStack)
{
	this->c = mutantStack.c;
	return (*this);
}

template <typename T>
MutantStack<T>::Iterator::Iterator(void)
	: ptr(NULL)
{ }

template <typename T>
MutantStack<T>::Iterator::Iterator(T *ptr)
	: ptr(ptr)
{ }

template <typename T>
MutantStack<T>::Iterator::Iterator(const T *ptr)
	: ptr(const_cast<T*>(ptr))
{ }

template <typename T>
MutantStack<T>::Iterator::Iterator(const Iterator &it)
{
	*this = it;
}

template <typename T>
typename MutantStack<T>::Iterator&	MutantStack<T>::Iterator::operator=
	(const MutantStack<T>::Iterator &it)
{
	this->ptr = it.ptr;
	return (*this);
}

template <typename T>
bool		MutantStack<T>::Iterator::operator==
	(const MutantStack<T>::Iterator &it)
{
	return (*(this->ptr) == *(it.ptr));
}

template <typename T>
bool		MutantStack<T>::Iterator::operator!=
	(const MutantStack<T>::Iterator &it)
{
	return (*(this->ptr) != *(it.ptr));
}

template <typename T>
T&			MutantStack<T>::Iterator::operator* ()
{
	return (*(this->ptr));
}

template <typename T>
typename MutantStack<T>::Iterator&	MutantStack<T>::Iterator::operator++ ()
{
	this->ptr--;
	return (*this);
}

template <typename T>
typename MutantStack<T>::Iterator&	MutantStack<T>::Iterator::operator-- ()
{
	this->ptr++;
	return (*this);
}

template <typename T>
typename MutantStack<T>::Iterator	MutantStack<T>::Iterator::operator++ (int)
{
	Iterator it(*this);
	this->ptr--;
	return (it);
}

template <typename T>
typename MutantStack<T>::Iterator	MutantStack<T>::Iterator::operator-- (int)
{
	Iterator it(*this);
	this->ptr++;
	return (it);
}

template <typename T>
typename MutantStack<T>::Iterator	MutantStack<T>::begin(void) const
{
	return (&this->top());
}

template <typename T>
typename MutantStack<T>::Iterator	MutantStack<T>::end(void) const
{
	return (&this->top() - this->size());
}

template <typename T>
std::ostream&	operator<< (std::ostream &out, const MutantStack<T> &mutantStack)
{
	out << "mutant stack with size " << mutantStack.size() << std::endl;
	int		i = 0;
	for (typename MutantStack<T>::Iterator it = mutantStack.begin();
		it != mutantStack.end(); ++it)
	{
		out << std::setw(5) << *it;
		if ((i + 1) % 10 == 0)
			out << std::endl;
		else
			out << " ";
		i++;
	}
	out << std::endl;
	return (out);
}

#endif
