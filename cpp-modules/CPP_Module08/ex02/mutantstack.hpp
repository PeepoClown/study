#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <iomanip>
#include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public :
		MutantStack(void);
		virtual ~MutantStack();
		MutantStack(const MutantStack &mutantStack);

		MutantStack&	operator= (const MutantStack &mutantStack);
	public :
		class	Iterator
		{
			private :
				T	*ptr;
			public :
				Iterator(void);
				Iterator(T *ptr);
				Iterator(const T *ptr);
				Iterator(const Iterator &it);

				Iterator&	operator= (const Iterator &it);
				bool		operator== (const Iterator &it);
				bool		operator!= (const Iterator &it);
				T&			operator* ();
				Iterator&	operator++ ();
				Iterator&	operator-- ();
				Iterator	operator++ (int);
				Iterator	operator-- (int);
		};
	public :
		Iterator	begin(void) const;
		Iterator	end(void) const;
};

template <typename T>
std::ostream&	operator<< (std::ostream &out, const MutantStack<T> &mutantStack);

#endif
