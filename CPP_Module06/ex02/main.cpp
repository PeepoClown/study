#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

class	Base
{
	public :
		virtual ~Base() { }
};

class	A : public Base { };

class	B : public Base { };

class	C : public Base { };

Base*	generate(void)
{
	srand(time(NULL));

	int		rand_value = rand() % 3;
	if (rand_value == 0)
	{
		std::cout << "generate A class object" << std::endl;
		return (new A);
	}
	else if (rand_value == 1)
	{
		std::cout << "generate B class object" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "generate C class object" << std::endl;
		return (new C);
	}
}

void	identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "pointer to A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "pointer to B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "pointer to C" << std::endl;
}

void	identify_from_reference(Base &p)
{
	try
	{
		A& ref_a = dynamic_cast<A&>(p);
		static_cast<void>(ref_a);
		std::cout << "reference to A" << std::endl;
	}
	catch (const std::exception &exception)
	{
		static_cast<void>(exception);
	}

	try
	{
		B& ref_b = dynamic_cast<B&>(p);
		static_cast<void>(ref_b);
		std::cout << "reference to B" << std::endl;
	}
	catch (const std::exception &exception)
	{
		static_cast<void>(exception);
	}

	try
	{
		C& ref_c = dynamic_cast<C&>(p);
		static_cast<void>(ref_c);
		std::cout << "reference to C" << std::endl;
	}
	catch (const std::exception &exception)
	{
		static_cast<void>(exception);
	}
}

int		main(void)
{
	for (int i = 0; i < 5; i++)
	{
		Base *ptr = generate();
		identify_from_pointer(ptr);
		identify_from_reference(*ptr);
		delete ptr;
		sleep(1);
	}

	return (0);
}
