C++ - Module 03: Inheritance

Version: 7.1

⸻

Table of Contents
	•	I. Introduction
	•	II. General Rules
	•	III. Exercise 00: Aaaaand… OPEN!
	•	IV. Exercise 01: Serena, my love!
	•	V. Exercise 02: Repetitive work
	•	VI. Exercise 03: Now it’s weird!
	•	VII. Submission and Peer-Evaluation

⸻

I. Introduction

C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, originally called “C with Classes” (source: Wikipedia).

The goal of these modules is to introduce you to Object-Oriented Programming (OOP) using C++.
We use C++98 to maintain simplicity and connection to C.

Reminder:
Modern C++ differs significantly. After the 42 Common Core, you are encouraged to go deeper on your own.

⸻

II. General Rules

Compiling
	•	Compile with:
c++ -Wall -Wextra -Werror
	•	Your code must also compile with:
-std=c++98

Formatting and Naming Conventions
	•	Directory names: ex00, ex01, …, exn
	•	Class names: UpperCamelCase (e.g., BrickWall)
	•	File names: Match the class name (e.g., BrickWall.hpp, BrickWall.cpp)
	•	All output must end with a newline.

Coding style:
	•	No strict style enforcement, but keep your code clean and readable.

Allowed / Forbidden
	•	You may use the C++ standard library (no C++11 or Boost).
	•	Forbidden functions:
	•	printf(), malloc(), calloc(), realloc(), free()
	•	Forbidden:
	•	using namespace <ns_name>
	•	friend keyword
	•	STL (until Modules 08 and 09)
	•	Forbidden Headers:
	•	<vector>, <list>, <map>, <algorithm>, etc.

Design Requirements
	•	Memory leaks are not allowed!
	•	Orthodox Canonical Form must be used (constructor, destructor, copy constructor, copy assignment operator).
	•	No implementation in header files (except for templates).
	•	Use include guards to avoid double inclusion.

Additional Notes
	•	Additional files are allowed if necessary.
	•	Read all instructions carefully, including examples.
	•	Use your brain. Be curious. Learn theory too.

Makefile:
Follow the same rules as in C.

⸻

III. Exercise 00: Aaaaand… OPEN!
	•	Turn-in directory: ex00/
	•	Files to turn in: Makefile, main.cpp, ClapTrap.{h,hpp}, ClapTrap.cpp
	•	Forbidden functions: None

Task

Implement a ClapTrap class with:

Private attributes:
	•	Name (passed in constructor)
	•	Hit points (10)
	•	Energy points (10)
	•	Attack damage (0)

Public member functions:
	•	void attack(const std::string& target);
	•	void takeDamage(unsigned int amount);
	•	void beRepaired(unsigned int amount);

Requirements
	•	Attacking and repairing cost 1 energy point.
	•	A ClapTrap cannot act without energy or hit points.
	•	Each action must print a descriptive message.
	•	Constructors and destructors must also print a message.
	•	Implement your own tests.

⸻

IV. Exercise 01: Serena, my love!
	•	Turn-in directory: ex01/
	•	Files to turn in: Previous exercise files + ScavTrap.{h,hpp}, ScavTrap.cpp
	•	Forbidden functions: None

Task

Create a ScavTrap class inheriting from ClapTrap.

Changes:
	•	New construction, destruction, and attack messages.
	•	Proper constructor/destructor chaining must be shown.

Attributes for ScavTrap:
	•	Name (passed in constructor)
	•	Hit points (100)
	•	Energy points (50)
	•	Attack damage (20)

Special function:
	•	void guardGate();
	•	Displays a message indicating gate keeper mode.

Additional:
Add more tests.

⸻

V. Exercise 02: Repetitive work
	•	Turn-in directory: ex02/
	•	Files to turn in: Previous exercise files + FragTrap.{h,hpp}, FragTrap.cpp
	•	Forbidden functions: None

Task

Create a FragTrap class inheriting from ClapTrap.

Changes:
	•	New construction, destruction, and attack messages.
	•	Proper constructor/destructor chaining must be shown.

Attributes for FragTrap:
	•	Name (passed in constructor)
	•	Hit points (100)
	•	Energy points (100)
	•	Attack damage (30)

Special function:
	•	void highFivesGuys(void);
	•	Displays a positive high-five request.

Additional:
Add more tests.

⸻

VI. Exercise 03: Now it’s weird!
	•	Turn-in directory: ex03/
	•	Files to turn in: Previous exercise files + DiamondTrap.{h,hpp}, DiamondTrap.cpp
	•	Forbidden functions: None

Task

Create a DiamondTrap class that inherits from both FragTrap and ScavTrap.

Attributes:
	•	Name (own private attribute, same variable name as ClapTrap)
	•	ClapTrap::name (with “_clap_name” suffix)

Use attributes:
	•	Hit points from FragTrap
	•	Energy points from ScavTrap
	•	Attack damage from FragTrap
	•	attack() from ScavTrap

Special function:
	•	void whoAmI();
	•	Displays both the DiamondTrap name and its ClapTrap name.

Important:
	•	The ClapTrap base must be constructed once, and only once.
	•	Pay attention to diamond inheritance!

Optional:
You can pass this module without completing Exercise 03.

⸻

VII. Submission and Peer-Evaluation
	•	Submit via Git repository.
	•	Only files in your repo will be evaluated.
	•	Double-check folder and file names!
