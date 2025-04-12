#include "Zombie.hpp"

Zombie::Zombie()//constructor
{
	this->name = "";
}

Zombie::~Zombie()//destructor
{
	std::cout << sb_toupper_str(this->name) << " is dead" << std::endl;
}

void Zombie::announce(int i)
{
	std::cout << sb_toupper_str(this->name) << " " << i << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

std::string sb_toupper_str(std::string src)
{
	std::string result;
	int i = -1;

	while (src[++i])
		result += toupper(src[i]);
	return (result);
}
