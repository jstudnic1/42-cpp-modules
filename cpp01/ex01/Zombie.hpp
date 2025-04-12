
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
	std::string name;

	public:
	void announce(int i);
	void setName(std::string name);

	Zombie();
	~Zombie();
};

Zombie* zombieHorde(int N, std::string name);
std::string sb_toupper_str(std::string src);
#endif
