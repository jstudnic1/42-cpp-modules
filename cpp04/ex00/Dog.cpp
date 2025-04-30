#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}
