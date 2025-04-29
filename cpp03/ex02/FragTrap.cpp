#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap("DefaultFrag_clap") // Initialize base
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " Parameterized constructor called" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	// Base members handled by ClapTrap(src)
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " Destructor called" << std::endl;
}

// Copy assignment operator
FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs); // Call base assignment operator
		// Assign any FragTrap-specific members here (if any)
	}
	return *this;
}

// attack override
void FragTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints--;
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else if (this->hitPoints <= 0)
		std::cout << "FragTrap " << this->name << " is already dead" << std::endl;
	else
		std::cout << "FragTrap " << this->name << " has no energy points to attack" << std::endl;
}

// highFivesGuys method
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << ": High five, everyone!" << std::endl; // Slightly modified message
}
