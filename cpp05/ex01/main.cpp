#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat john("John", 5);
        Bureaucrat bob("Bob", 140);

        Form taxForm("TaxForm", 50, 25);
        Form vacationForm("VacationForm", 150, 100);

        std::cout << "\n--- Before signing ---" << std::endl;
        std::cout << taxForm;
        std::cout << vacationForm;

        std::cout << "\n--- Signing attempts ---" << std::endl;
        john.signForm(taxForm);       // should succeed
        bob.signForm(taxForm);        // should fail
        bob.signForm(vacationForm);   // should succeed

        std::cout << "\n--- After signing ---" << std::endl;
        std::cout << taxForm;
        std::cout << vacationForm;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
