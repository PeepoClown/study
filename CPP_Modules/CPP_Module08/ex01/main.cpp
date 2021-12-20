#include "Span.hpp"
#include <iostream>
#include <vector>
#include <random>

int		main(void)
{
	std::vector<int> vector;

	vector.push_back(-3);
	vector.push_back(4);
	vector.push_back(102);
	vector.push_back(0);
	vector.push_back(-1);
	vector.push_back(1);
	vector.push_back(-56);
	Span vecSpan;
	vecSpan.fillArray(vector, 7);
	vecSpan.print();
	vecSpan.print_span();

	std::cout << std::endl << "===============================================" << std::endl;

	std::vector<int> vector1;

	std::default_random_engine generator;
	generator.seed(std::time(nullptr));
	std::uniform_int_distribution<int> distribution(-1000, 0000);
	for (int i = 0; i < 1000; i++)
		vector1.push_back(distribution(generator));
	Span vecSpan1;
	vecSpan1.fillArray(vector1, 1000);
	vecSpan1.print();
	vecSpan1.print_span();

	std::cout << std::endl << "===============================================" << std::endl;

	std::vector<int> vector2;

	generator.seed(std::time(nullptr));
	for (int i = 0; i < 10000; i++)
		vector2.push_back(distribution(generator));
	Span vecSpan2;
	vecSpan2.fillArray(vector2, 10000);
	vecSpan2.print_span();

	std::cout << std::endl << "===============================================" << std::endl;

	try
	{
		Span span(3);
		span.addNumber(-10);
		span.addNumber(7);
		span.addNumber(7);
		span.print();
		span.print_span();
		span.addNumber(7);
	}
	catch (const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	std::cout << std::endl << "===============================================" << std::endl;

	try
	{
		Span span(1);
		span.addNumber(-10);
		span.print();
		span.print_span();
	}
	catch (const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	std::cout << std::endl << "===============================================" << std::endl;

	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return (0);
}
