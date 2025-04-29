#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
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
	if (this->hitPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
		return;
	}

	if (static_cast<int>(amount) >= this->hitPoints) {
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage and is destroyed!" << std::endl;
	} else {
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints--;
		this->hitPoints += amount;
		std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points!" << std::endl;
	}
	else if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " cannot be repaired, it's already destroyed!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " has no energy points to repair itself!" << std::endl;
}
