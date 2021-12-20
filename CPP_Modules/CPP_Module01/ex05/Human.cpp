#include "Human.hpp"

Human::Human(void)
	: brain("human")
{ }

std::string		Human::identify(void)
{
	return (this->brain.identify());
}

const Brain&	Human::getBrain(void)
{
	return (this->brain);
}
