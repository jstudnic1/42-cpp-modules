#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat paul("Paul", 150);
        ShrubberyCreationForm form("home");
        ShrubberyCreationForm formInvalid("invalid_home");
        RobotomyRequestForm robotForm("robot_target");
        PresidentialPardonForm pardonForm("big_boss");

        std::cout << bob << std::endl;
        std::cout << form << std::endl;
        std::cout << formInvalid << std::endl;
        std::cout << robotForm << std::endl;
        std::cout << pardonForm << std::endl;

        bob.signForm(robotForm);
        bob.signForm(form);
        bob.signForm(pardonForm);
        std::cout << form << std::endl;
        std::cout << pardonForm << std::endl;

        paul.signForm(robotForm);
        paul.signForm(formInvalid);
        std::cout << formInvalid << std::endl;
        bob.executeForm(robotForm);
        paul.executeForm(formInvalid);
        std::cout << robotForm << std::endl;
        paul.executeForm(robotForm);

        bob.executeForm(form);
        bob.executeForm(pardonForm);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
