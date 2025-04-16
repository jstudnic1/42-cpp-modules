#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap scavtrap_copy("x013");
    ClapTrap claptrap("x011");
	ScavTrap scavtrap("x012");
    claptrap.attack("Target1");
	scavtrap.attack("Target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    claptrap.takeDamage(10);
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.takeDamage(5);
    return 0;
}
