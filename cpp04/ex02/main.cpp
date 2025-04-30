#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;

	std::cout << "\n--- Array Test ---\n" << std::endl;

	const int arraySize = 4;
	AAnimal* animals[arraySize];

	for (int k = 0; k < arraySize / 2; ++k) {
		animals[k] = new Dog();
	}
	for (int k = arraySize / 2; k < arraySize; ++k) {
		animals[k] = new Cat();
	}

	for (int k = 0; k < arraySize; ++k) {
		delete animals[k];
	}

	std::cout << "\n--- Deep Copy Test (Basic) ---\n" << std::endl;

	Dog originalDog;
	{
		Dog copiedDog = originalDog;
		Dog assignedDog;
		assignedDog = originalDog;
	}

	std::cout << "\n--- Main finished ---\n" << std::endl;
	return 0;
}
