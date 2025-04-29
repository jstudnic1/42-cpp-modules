#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Basic Tests ---" << std::endl;
    ClapTrap claptrap("C-3PO");
	ScavTrap scavtrap("R2-D2");
	FragTrap fragtrap("C-3PO");

    claptrap.attack("Target1"); // ClapTrap attacks
	scavtrap.attack("Target1"); // ScavTrap attacks (uses overridden method)
	fragtrap.attack("Target1"); // FragTrap attacks (uses overridden method)
	std::cout << "\n--- FragTrap Specific Test ---" << std::endl;
	fragtrap.highFivesGuys(); // Test highFivesGuys

	std::cout << "\n--- Damage & Repair ---" << std::endl;
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(10);
	fragtrap.takeDamage(30);
	fragtrap.beRepaired(10);

	std::cout << "\n--- OCF Tests ---" << std::endl;
	FragTrap fragtrap_copy(fragtrap); // Test Copy Constructor
	fragtrap_copy.attack("Another Target");

	FragTrap fragtrap_assign("TEMP");
	fragtrap_assign = fragtrap; // Test Copy Assignment Operator
	fragtrap_assign.highFivesGuys();


	std::cout << "\n--- Exhaustion Test ---" << std::endl;
    claptrap.takeDamage(10);
	claptrap.attack("Target2"); // Should fail (no HP)
	claptrap.beRepaired(5);    // Should fail (no HP)
	scavtrap.takeDamage(10);
	scavtrap.attack("Target2"); // Should fail (no HP)
	scavtrap.beRepaired(5);    // Should fail (no HP)
	fragtrap.takeDamage(10);
	fragtrap.attack("Target2"); // Should fail (no HP)
	fragtrap.beRepaired(5);    // Should fail (no HP)


	std::cout << "\n--- Destruction ---" << std::endl;
    return 0;
}
