#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	this->type = other.type;
	this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
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

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}
