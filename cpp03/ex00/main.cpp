#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap claptrap("x011");

    claptrap.attack("Target1");
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
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.attack("Target2");
	claptrap.takeDamage(5);
    return 0;
}
