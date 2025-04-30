#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// WrongAnimal
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();

	WrongAnimal* wrongMeta = new WrongAnimal();
	WrongAnimal* wrongJ = new WrongDog();
	WrongAnimal* wrongI = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrongJ->getType() << " " << std::endl;
	std::cout << wrongI->getType() << " " << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound();

	wrongMeta->makeSound();
	wrongJ->makeSound();
	wrongI->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongJ;
	delete wrongI;

	return 0;
}
