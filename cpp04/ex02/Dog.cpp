#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
	this->_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
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
