#include "Span.hpp"

Span::Span(void)
{ }

Span::~Span()
{ }

Span::Span(unsigned int n)
{
	this->array.reserve(static_cast<std::size_t>(n));
}

Span::Span(const Span &span)
{
	*this = span;
}

Span&	Span::operator= (const Span &span)
{
	this->array.erase(this->array.begin(), this->array.end());

	this->array.reserve(span.array.size());
	for (std::vector<int>::const_iterator it = span.array.cbegin();
		it != span.array.cend(); it++)
		this->array.push_back(*it);
	return (*this);
}

void		Span::addNumber(int number)
{
	if (this->array.size() + 1 > this->array.capacity())
		throw std::runtime_error("array is full");
	this->array.push_back(number);
}

void		Span::fillArray(const std::vector<int> &vector,
	std::size_t capacity)
{
	this->array.erase(this->array.begin(), this->array.end());

	this->array.reserve(capacity);
	std::size_t	i = 0;
	for (std::vector<int>::const_iterator it = vector.cbegin();
		it != vector.end() && i < capacity; it++)
	{
		this->array.push_back(*it);
		i++;
	}
}

int			Span::shortestSpan(void) const
{
	if (this->array.size() < 2)
		throw std::runtime_error("there is no span in array");

	int		shortestSpan = std::abs(*(this->array.cbegin() + 1) -
		*(this->array.cbegin()));
	for (std::vector<int>::const_iterator it = this->array.cbegin();
		it != this->array.end(); it++)
	{
		for (std::vector<int>::const_iterator jt = it + 1;
			jt != this->array.end(); jt++)
		{
			if (std::abs(*jt - *it) < shortestSpan)
				shortestSpan = std::abs(*jt - *it);
		}
	}
	return (shortestSpan);
}

int			Span::longestSpan(void) const
{
	if (this->array.size() < 2)
		throw std::runtime_error("there is no span in array");

	int		longestSpan = std::abs(*(this->array.cbegin() + 1) -
		*(this->array.cbegin()));
	for (std::vector<int>::const_iterator it = this->array.cbegin();
		it != this->array.end(); it++)
	{
		for (std::vector<int>::const_iterator jt = it + 1;
			jt != this->array.end(); jt++)
		{
			if (std::abs(*jt - *it) > longestSpan)
				longestSpan = std::abs(*jt - *it);
		}
	}
	return (longestSpan);
}

void		Span::print(void) const
{
	int		i = 0;

	std::cout << "size : " << this->array.size() << ", capacity : "
		<< this->array.capacity() << std::endl;
	for (std::vector<int>::const_iterator it = this->array.begin();
		it != this->array.end(); it++)
	{
		std::cout << std::setw(5) << *it;
		if ((i + 1) % 10 == 0)
			std::cout << std::endl;
		else
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
}

void		Span::print_span(void) const
{
	std::cout << "shortest span : " << shortestSpan() << std::endl;
	std::cout << "longest span : " << longestSpan() << std::endl;
}

std::size_t	Span::size(void) const
{
	return (this->array.size());
}
