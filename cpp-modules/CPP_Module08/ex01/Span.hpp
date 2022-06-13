#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <iomanip>
#include <exception>
#include <vector>
#include <string>
#include <cmath>

class	Span
{
	private :
		std::vector<int>	array;
	public :
		Span(void);
		~Span();
		explicit Span(unsigned int n);
		Span(const Span &span);

		Span&	operator= (const Span &span);

		void		addNumber(int number);
		void		fillArray(const std::vector<int> &vector, std::size_t capacity);
		int			shortestSpan(void) const;
		int			longestSpan(void) const;
		void		print(void) const;
		void		print_span(void) const;
		std::size_t	size(void) const;
};

#endif
