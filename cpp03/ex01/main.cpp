#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Basic Tests ---" << std::endl;
    ClapTrap claptrap("C-3PO");
	ScavTrap scavtrap("R2-D2");

    claptrap.attack("Target1"); // ClapTrap attacks
	scavtrap.attack("Target1"); // ScavTrap attacks (uses overridden method)

	std::cout << "\n--- ScavTrap Specific Test ---" << std::endl;
	scavtrap.guardGate(); // Test guardGate

	std::cout << "\n--- Damage & Repair ---" << std::endl;
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(10);

	std::cout << "\n--- OCF Tests ---" << std::endl;
	ScavTrap scavtrap_copy(scavtrap); // Test Copy Constructor
	scavtrap_copy.attack("Another Target");

	ScavTrap scavtrap_assign("TEMP");
	scavtrap_assign = scavtrap; // Test Copy Assignment Operator
	scavtrap_assign.guardGate();


	std::cout << "\n--- Exhaustion Test ---" << std::endl;
    claptrap.takeDamage(10);
	claptrap.attack("Target2"); // Should fail (no HP)
	claptrap.beRepaired(5);    // Should fail (no HP)


	std::cout << "\n--- Destruction ---" << std::endl;
    // Destructors called automatically when objects go out of scope
    return 0;
}
