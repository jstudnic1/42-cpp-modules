#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " << this->name << " created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " has no energy points to attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0)
	{
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0)
	{
		this->energyPoints--;
		this->hitPoints += amount;
		std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no energy points to repair" << std::endl;
}
