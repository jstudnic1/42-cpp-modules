#include "ScavTrap.hpp"

// Default Constructor (may be needed for DiamondTrap initialization)
ScavTrap::ScavTrap() : ClapTrap("DefaultScav_clap") // Initialize base
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

// Parameterized Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // Call base constructor
{
	// Set ScavTrap specific values (overrides base defaults)
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " Parameterized constructor called" << std::endl;
}

// Copy Constructor Definition
ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) // Call base copy constructor
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	// If ScavTrap had its own members, we'd copy them here.
	// Base members handled by ClapTrap(src)
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " Destructor called" << std::endl;
}

// Copy Assignment Operator Definition
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs); // Call base class operator=
		// Assign any ScavTrap-specific members here (if any)
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints--;
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else if (this->hitPoints <= 0)
		std::cout << "ScavTrap " << this->name << " is already dead" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " has no energy points to attack" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}
