#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <fstream>

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

static AForm* createShrubberyForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    typedef AForm* (*FormCreator)(const std::string& target);
    struct FormType {
        std::string name;
        FormCreator creator;
    };

    FormType formTypes[] = {
        {"shrubbery creation", createShrubberyForm},
        {"robotomy request", createRobotomyForm},
        {"presidential pardon", createPresidentialForm}
    };

    for (size_t i = 0; i < sizeof(formTypes) / sizeof(FormType); ++i) {
        if (formName == formTypes[i].name) {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formTypes[i].creator(target);
        }
    }

    std::cout << "Intern could not find the form: " << formName << std::endl;
    return nullptr;
}
