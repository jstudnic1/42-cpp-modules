#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal")
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal sound" << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}
