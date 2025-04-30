# CPP Module 03 Evaluation Guide

## Introduction
- Remain polite, constructive, and respectful.
- Discuss any identified project issues openly.
- Respect differences in interpretation and grade honestly.

## Guidelines
- Only grade from the evaluated student's Git repository.
- Verify the correct repository and clean cloning.
- Ensure no malicious scripts are used.
- Review testing/automation scripts if available.
- If you haven't done the project yourself, read the subject carefully.
- Use flags for:
  - Empty repo
  - Non-functioning program
  - Norm errors
  - Cheating (grade -42)

- Memory leaks are forbidden (use `leaks`, `valgrind`, or `e_fence`).

## Prerequisites
- Compile with `c++` and flags `-Wall -Wextra -Werror`.
- Follow **C++98** standard.
- Forbidden:
  - Functions in header files (except templates)
  - Non-c++ compiler or missing flags
  - C functions like `malloc`, `printf`, `free`
  - `using namespace`
  - `friend` keyword
  - External libraries or C++11+ features

## Exercises

### Ex00: Aaaaand... OPEN!
- `ClapTrap` class:
  - Private attributes: `name`, `hit points`, `energy points`, `attack damage`
  - Functions: `attack()`, `takeDamage()`, `beRepaired()`
  - Attributes initialized correctly.
- Sufficient tests must be provided.

### Ex01: Serena, my love!
- `ScavTrap` class:
  - Inherits **publicly** from `ClapTrap`.
  - `ClapTrap` attributes become **protected**.
  - Constructor, destructor, and `attack()` output **must differ** from `ClapTrap`.
  - Special functions:
    - `guardGate()`
    - Modified `attack()`

### Ex02: Repetitive work
- `FragTrap` class:
  - Inherits **publicly** from `ClapTrap`.
  - No attribute redeclaration without reason.
  - Constructor and destructor must print specific messages.
  - Special function:
    - `highFivesGuys()`

### Ex03: Now it is weird!
- `DiamondTrap` class:
  - Inherits from **FragTrap** and **ScavTrap** (use **virtual inheritance**).
  - Private attribute: `std::string name`.
  - Uses `attack()` from `ScavTrap`.
  - Has special functions from both parents.
  - Special function:
    - `whoAmI()` (displays both `name` and `ClapTrap::name`)

## Ratings
- Flags:
  - Ok
  - Outstanding project
  - Empty work
  - No author file
  - Invalid compilation
  - Norm error
  - Cheat
  - Crash
  - Leaks
  - Forbidden function

## Conclusion
- Leave a comment after evaluation.

---
Reference: [subject.pdf](https://cdn.intra.42.fr/pdf/pdf/41485/en.subject.pdf)
