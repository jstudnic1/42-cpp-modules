#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
	this->type = "WrongDog";
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other)
{
	this->type = other.type;
}

WrongDog& WrongDog::operator=(const WrongDog& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructor called" << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}
