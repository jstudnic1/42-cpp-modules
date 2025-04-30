#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Subject Example: Basic polymorphic deletion
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; // Must call Dog destructor via virtual ~Animal()
	delete i; // Must call Cat destructor via virtual ~Animal()

	std::cout << "\n--- Array Test ---\n" << std::endl;

	// Subject Requirement: Array of Animals
	const int arraySize = 4; // Example size
	Animal* animals[arraySize];

	// Fill array
	for (int k = 0; k < arraySize / 2; ++k) {
		animals[k] = new Dog();
	}
	for (int k = arraySize / 2; k < arraySize; ++k) {
		animals[k] = new Cat();
	}

	// Delete array elements through base pointers
	for (int k = 0; k < arraySize; ++k) {
		delete animals[k]; // Tests virtual destructor for leaks
	}

	std::cout << "\n--- Deep Copy Test (Basic) ---\n" << std::endl;

	// Subject Recommendation: Test deep copies
	Dog originalDog;
	{
		Dog copiedDog = originalDog;    // Test copy constructor
		Dog assignedDog;
		assignedDog = originalDog;  // Test assignment operator
		// copiedDog and assignedDog destroyed here, testing their destructors
	}
	// originalDog destroyed here

	std::cout << "\n--- Main finished ---\n" << std::endl;
	// Remember to check for leaks!
	return 0;
}
