#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap " << this->name << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}

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

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " high fives everyone" << std::endl;
}
