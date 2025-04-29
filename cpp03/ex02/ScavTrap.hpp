#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(std::string name = "DefaultScav");
		ScavTrap();
		ScavTrap(const ScavTrap &src);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &rhs);

		// methods
		void attack(const std::string& target);
		void guardGate();
};

#endif
