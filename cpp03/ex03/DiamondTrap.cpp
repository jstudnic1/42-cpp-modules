#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
	{
		this->hitPoints = 100;
		this->energyPoints = 50;
		this->attackDamage = 30;

		std::cout << "DiamondTrap " << this->_name << " Parameterized constructor called" << std::endl;
		std::cout << "  - My name: " << this->_name << std::endl;
		std::cout << "  - ClapTrap name: " << ClapTrap::name << std::endl;
	}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
	: ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)
	{
		std::cout << "DiamondTrap Copy constructor called" << std::endl;
	}

DiamondTrap::~DiamondTrap()
	{
		std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
	}


DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
	{
		std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
		if (this != &rhs) {
			ScavTrap::operator=(rhs);
			FragTrap::operator=(rhs);

			this->_name = rhs._name;
		}
		return *this;
	}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap reporting for duty!" << std::endl;
	std::cout << "  My DiamondTrap name is: " << this->_name << std::endl;
	std::cout << "  My ClapTrap name is: " << ClapTrap::name << std::endl;
}
