#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	// Optionally initialize ideas array here if needed
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = "some idea"; // Example initialization
	}
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other; // Use assignment operator logic
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			this->ideas[i] = other.ideas[i]; // Copy ideas
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
