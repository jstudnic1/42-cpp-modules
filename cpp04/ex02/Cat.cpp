#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
	this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
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
