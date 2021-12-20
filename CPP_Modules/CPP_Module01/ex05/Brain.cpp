#include "Brain.hpp"

Brain::Brain(void)
	: owner("")
{ }

Brain::Brain(const std::string &owner)
	: owner(owner)
{ }

std::string	Brain::identify(void) const
{
	std::stringstream sStream;
	sStream << this;
	return (sStream.str());
}
