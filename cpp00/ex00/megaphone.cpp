#include <iostream>
#include <cctype>

void print_argument(char *argument)
{
	while (*argument != '\0')
	{
		if (std::isalpha(*argument))
			std::cout << (char)std::toupper(*argument);
		else
			std::cout << *argument;
		argument++;
	}
}

int main(int argc, char **argv)
{
	char **args;

	args = ++argv;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (*args != NULL)
			{
				print_argument(*args);
				args++;
			}
		std::cout << std::endl;
	}
	return (0);
}
