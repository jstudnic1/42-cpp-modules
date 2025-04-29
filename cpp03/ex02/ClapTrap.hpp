#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
class ClapTrap
{
	protected:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
	public:
		// Constructors and Destructor
		ClapTrap(std::string name);
		~ClapTrap();

		// Member functions
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Getters
		std::string getName() const;
		int getHP() const;
		int getEnergyPoints() const;
};

#endif
