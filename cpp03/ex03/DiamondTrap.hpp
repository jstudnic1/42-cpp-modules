#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		// DiamondTrap's own name, shadowing ClapTrap's name
		std::string _name;

	public:
		// Constructor - Takes its own name, passes formatted name to ClapTrap
		DiamondTrap(std::string name);

		// OCF
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &rhs);

		// Use ScavTrap's attack (needs an override to specify this)
		void attack(const std::string& target);

		// Specific function
		void whoAmI();
};

#endif
