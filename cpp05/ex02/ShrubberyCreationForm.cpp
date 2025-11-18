#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137, "DefaultTarget")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137, target)
{
    std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream outfile((getTarget() + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cerr << "Error: Could not open file " << getTarget() + "_shrubbery" << std::endl;
        return;
    }

    outfile << "       _-_       \n"
               "    /~~   ~~\\    \n"
               " /~~         ~~\\ \n"
               "{               }\n"
               " \\  _-     -_  / \n"
               "   ~  \\\\ //  ~  \n"
               "_- -   | | _- _  \n"
               "  _ -  | |   -_  \n"
               "      // \\\\       \n";

    outfile.close();
    std::cout << "Shrubbery created successfully at " << getTarget() + "_shrubbery" << std::endl;
}
