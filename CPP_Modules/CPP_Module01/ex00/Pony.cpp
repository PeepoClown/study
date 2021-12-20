#include "Pony.hpp"

Pony::Pony(void)
	: name(""), height(0), weight(0)
{ }

Pony::Pony(const std::string &name, size_t height, size_t weight)
	: name(name), height(height), weight(weight)
{ }

void	Pony::doSmth(void)
{
	std::cout << this->name << " delaet " << "tigdyk tigdyk..." << std::endl;
	std::cout << "weight : " << this->weight << " height " << this->height << std::endl;
}
