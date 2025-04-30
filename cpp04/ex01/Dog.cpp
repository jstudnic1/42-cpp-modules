#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	this->type = other.type;
	this->_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->type = other.type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}
