#include "Zombie.hpp"

Zombie::Zombie()//constructor
{
	this->name = "";
}

Zombie::~Zombie()//destructor
{
	std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
