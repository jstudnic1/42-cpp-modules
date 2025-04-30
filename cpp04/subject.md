C++ - Module 04:

Subtype Polymorphism, Abstract Classes, and Interfaces

Version: 11.1

⸻

Table of Contents
	•	I. Introduction
	•	II. General Rules
	•	III. Exercise 00: Polymorphism
	•	IV. Exercise 01: I don’t want to set the world on fire
	•	V. Exercise 02: Abstract class
	•	VI. Exercise 03: Interface & Recap
	•	VII. Submission and Peer Evaluation

⸻

I. Introduction

C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language (“C with Classes” — source: Wikipedia).

The goal of these modules is to introduce you to Object-Oriented Programming (OOP) with C++.
We follow the C++98 standard for simplicity and compatibility.
Modern C++ differs significantly, so continue studying after the 42 Common Core to become a proficient developer.

⸻

II. General Rules

Compiling
	•	Compile with:
c++ -Wall -Wextra -Werror
	•	Code must also compile with:
-std=c++98

Formatting and Naming Conventions
	•	Directory names: ex00, ex01, …, exn
	•	Class names: UpperCamelCase format.
	•	File names must match the class name (e.g., BrickWall.hpp, BrickWall.cpp).
	•	Every output must end with a newline character.

Coding style:
	•	No strict enforcement, but code must be clean and readable.

Allowed / Forbidden
	•	Allowed:
	•	Almost everything from the standard C++ library.
	•	Forbidden:
	•	printf(), malloc(), calloc(), realloc(), free()
	•	using namespace <ns_name>
	•	friend keyword
	•	STL (until Modules 08 and 09)

Design Requirements
	•	Avoid memory leaks (especially when using new).
	•	Classes must follow the Orthodox Canonical Form (Module 02 to 09).
	•	No function implementations in headers (except templates).
	•	Use include guards to prevent double inclusion.

Additional Notes
	•	You can add extra files to organize your code.
	•	Always read the full module before starting.
	•	Think carefully and read examples!

Makefile:
Follow the same rules as in C.

⸻

III. Exercise 00: Polymorphism
	•	Turn-in directory: ex00/
	•	Files to turn in: Makefile, main.cpp, *.cpp, *.{h,hpp}
	•	Forbidden functions: None

Task

Create:
	•	A Animal class with a protected attribute:
	•	std::string type
	•	A Dog class that inherits from Animal.
	•	A Cat class that inherits from Animal.

Set the type field appropriately (“Dog” or “Cat”).

Public Member Functions:
	•	makeSound(): Outputs the animal’s sound (cats do not bark).

Example:
int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    return 0;
}
Additionally, implement:
	•	WrongAnimal and WrongCat classes to demonstrate incorrect polymorphism behavior.

Create more tests than the given examples.

⸻

IV. Exercise 01: I don’t want to set the world on fire
	•	Turn-in directory: ex01/
	•	Files to turn in: Files from previous exercise + new *.cpp, *.{h,hpp}
	•	Forbidden functions: None

Task

Create a Brain class with an array of 100 std::string called ideas.
	•	Dog and Cat classes will have a private Brain* attribute.
	•	Dogs and Cats:
	•	new Brain() upon construction
	•	delete Brain upon destruction
	•	Deep copy must be performed when copying.

Main Example:
int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
    return 0;
}
Also:
	•	Create an array of Animal* (half Dogs, half Cats).
	•	Delete each Animal directly through an Animal*.
	•	Check for memory leaks.

Add more tests to verify deep copies.

⸻

V. Exercise 02: Abstract class
	•	Turn-in directory: ex02/
	•	Files to turn in: Files from previous exercise + new *.cpp, *.{h,hpp}
	•	Forbidden functions: None

Task

Make the Animal class abstract to prevent instantiation.
	•	Introduce at least one pure virtual function (e.g., makeSound()).
	•	Keep existing functionality intact.
	•	(Optionally rename Animal to AAnimal for clarity.)

⸻

VI. Exercise 03: Interface & Recap
	•	Turn-in directory: ex03/
	•	Files to turn in: Makefile, main.cpp, *.cpp, *.{h,hpp}
	•	Forbidden functions: None

Task

Implement a Materia system inspired by RPGs.

⸻

Step 1: Define AMateria
class AMateria {
protected:
    std::string type;
public:
    AMateria(std::string const& type);
    virtual ~AMateria();
    std::string const& getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};
Step 2: Concrete Materia classes
	•	Ice: "ice"
	•	Cure: "cure"

Their use() must output:
	•	Ice: * shoots an ice bolt at <name> *
	•	Cure: * heals <name>'s wounds *

Their clone() must return a new object of their type.

⸻

Step 3: Define ICharacter
class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
	•	Characters have 4 inventory slots for Materias.
	•	equip() fills the first available slot.
	•	unequip() does not delete the Materia.
	•	Copying Characters must perform deep copies.

⸻

Step 4: Define MateriaSource
class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};
	Store up to 4 Materias.
	•	learnMateria() stores a Materia copy.
	•	createMateria() generates a new copy based on type.

⸻

Step 5: Final Main Example
int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    return 0;
}
Expected Output:
* shoots an ice bolt at bob *
* heals bob's wounds *
Note:
You can pass the module without completing Exercise 03.

⸻

VII. Submission and Peer Evaluation
	•	Submit through your Git repository.
	•	Only the files in your repository will be evaluated.
	•	Double-check the folder and file names carefully!

⸻

Would you also like me to prepare a ready-to-go folder structure and Makefile template for Module 04 as well? 🚀
It would help you get started super quickly!
