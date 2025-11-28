#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void)
{
	int r = std::rand() % 3;
	if (r == 0)
		return new A();
	else if (r == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception&) {}

	std::cout << "Unknown" << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	std::cout << "--- Test 1 ---" << std::endl;
	Base* p1 = generate();
	std::cout << "Pointer identify: ";
	identify(p1);
	std::cout << "Reference identify: ";
	identify(*p1);
	delete p1;

	std::cout << "\n--- Test 2 ---" << std::endl;
	Base* p2 = generate();
	std::cout << "Pointer identify: ";
	identify(p2);
	std::cout << "Reference identify: ";
	identify(*p2);
	delete p2;

	std::cout << "\n--- Test 3 ---" << std::endl;
	Base* p3 = generate();
	std::cout << "Pointer identify: ";
	identify(p3);
	std::cout << "Reference identify: ";
	identify(*p3);
	delete p3;

	std::cout << "\n--- Test 4 ---" << std::endl;
	Base* p4 = generate();
	std::cout << "Pointer identify: ";
	identify(p4);
	std::cout << "Reference identify: ";
	identify(*p4);
	delete p4;

	return 0;
}
