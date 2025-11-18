#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat employee("Employee", 150);

    AForm* shrub = intern.makeForm("shrubbery creation", "Home");
    AForm* robo = intern.makeForm("robotomy request", "Bender");
    AForm* pardon = intern.makeForm("presidential pardon", "Arthur");
    AForm* invalid = intern.makeForm("coffee break", "Nowhere");

    if (shrub) {
        employee.signForm(*shrub);
        boss.signForm(*shrub);
        employee.executeForm(*shrub);
        boss.executeForm(*shrub);
    }

    if (robo) {
        employee.signForm(*robo);
        boss.signForm(*robo);
        employee.executeForm(*robo);
        boss.executeForm(*robo);
    }

    if (pardon) {
        employee.signForm(*pardon);
        boss.signForm(*pardon);
        employee.executeForm(*pardon);
        boss.executeForm(*pardon);
    }

    delete shrub;
    delete robo;
    delete pardon;
    delete invalid;

    return 0;
}
