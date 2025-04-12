
#include <iostream>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

int main()
{
	std::cout << RED << "Variables " << RES << "& " << GRE << "pointers" << RES << " &" << YEL << "references" << RES << " in C++" << std::endl;
	std::string brain = "HI THIS IS BRAIN";

	std::cout <<"\nstd::string " << RED << "brain " << RES << "= \"HI THIS IS BRAIN\";" << std::endl;

	std::string *stringPTR = &brain;
	std::cout <<"\nstd::string *" << RED << "stringPTR " << RES << "= &brain;" << std::endl;

	std::string &stringREF = brain;
	std::cout <<"\nstd::string &" << RED << "stringREF " << RES << "= brain;" << std::endl;

	std::cout << "\nMemory address of \"brain\" " << RED << "variable (&brain): " << RES << "\t\t" << RED << &brain << RES << std::endl;
	std::cout << "Memory address held by " << GRE << "stringPTR (stringPTR): " << RES << "\t\t" << RED << stringPTR << RES << std::endl;
	std::cout << "Memory address of the " << GRE << "stringPTR itself (&stringPTR): " << RES << "\t" << GRE << &stringPTR << RES << std::endl;
	std::cout << "Memory address held by " << YEL << "stringREF (&stringREF): " << RES << "\t\t" << RED << &stringREF << RES << std::endl << std::endl;

	std::cout << "The value of \"brain\" " << RED << "variable (brain): " << RES << brain << std::endl;
	std::cout << "The value pointed to by " << GRE << "stringPTR (*stringPTR): " << RES << *stringPTR << std::endl;
	std::cout << "The value pointed to by " << YEL << "stringREF (stringREF): " << RES << stringREF << std::endl << std::endl;

	return 0;
}
