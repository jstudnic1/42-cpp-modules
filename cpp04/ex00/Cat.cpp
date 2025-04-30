#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	this->type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}
