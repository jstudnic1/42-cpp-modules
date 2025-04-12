
#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		std::cout << "\033[31m" << "\nFOR THE HORDE (ON THE HEAP) !!!" << "\033[0m" << std::endl;
		std::cout << "\nZombies about to allocated on a heap: " << atoi(av[1]) << std::endl << std::endl;
		std::cout << "\"..Grhhhr...we are all " << sb_toupper_str(av[2]) << "!!\"\n"<< std::endl;

		Zombie *horde = zombieHorde(atoi(av[1]), av[2]);
		delete[] horde;
		std::cout << "\nHorde deleted from a heap\n" << std::endl;
		return 0;
	}
	return (std::cerr << "Error: specify the horde size and name for zombies!" << std::endl, 1);
}
