#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Constructing ---" << std::endl;
	DiamondTrap dt("Ash");
	std::cout << std::endl;

	std::cout << "--- Testing whoAmI ---" << std::endl;
	dt.whoAmI();
	std::cout << std::endl;

	std::cout << "--- Testing attack (should use ScavTrap::attack) ---" << std::endl;
	dt.attack("Team Rocket");
	std::cout << std::endl;

	std::cout << "--- Testing inherited functions ---" << std::endl;
	dt.takeDamage(25);
	dt.beRepaired(10);
	dt.guardGate(); // From ScavTrap
	dt.highFivesGuys(); // From FragTrap
	std::cout << std::endl;

	std::cout << "--- Testing OCF ---" << std::endl;
	DiamondTrap dt2 = dt; // Copy constructor
	dt2.whoAmI();

	DiamondTrap dt3("Gary");
	dt3 = dt; // Copy assignment
	dt3.whoAmI();
	std::cout << std::endl;


	std::cout << "--- Destructing ---" << std::endl;
	return 0;
}
