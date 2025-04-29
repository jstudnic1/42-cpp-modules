#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
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
