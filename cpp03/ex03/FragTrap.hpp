#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		~FragTrap();
		FragTrap &operator=(const FragTrap &rhs);

		// methods
		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif
