#include "Bureaucrat.hpp"

int main()
{
    // Test 1: Default constructor
    try {
        Bureaucrat b1;
        std::cout << b1;
    }
    catch (std::exception &e) {
        std::cerr << "Error (default constructor): " << e.what() << std::endl;
    }

    // Test 2: Valid custom grades
    try {
        Bureaucrat b2("John", 1);
        Bureaucrat b3("Jane", 150);
        std::cout << b2;
        std::cout << b3;
    }
    catch (std::exception &e) {
        std::cerr << "Error (valid grades): " << e.what() << std::endl;
    }

    // Test 3: Invalid too high grade
    try {
        Bureaucrat b4("Jim", 0);
        std::cout << b4;
    }
    catch (std::exception &e) {
        std::cerr << "Error (too high grade): " << e.what() << std::endl;
    }

    // Test 4: Invalid too low grade
    try {
        Bureaucrat b5("Pepa", 151);
        std::cout << b5;
    }
    catch (std::exception &e) {
        std::cerr << "Error (too low grade): " << e.what() << std::endl;
    }

    // Test 5: Increment / decrement edge cases
    try {
        Bureaucrat b6("Adam", 2);
        std::cout << b6;
        b6.incrementGrade(); // should become grade 1
        std::cout << "After increment: " << b6;
        b6.incrementGrade(); // should throw
    }
    catch (std::exception &e) {
        std::cerr << "Error (increment): " << e.what() << std::endl;
    }

    try {
        Bureaucrat b7("Eve", 150);
        std::cout << b7;
        b7.decrementGrade(); // should throw
    }
    catch (std::exception &e) {
        std::cerr << "Error (decrement): " << e.what() << std::endl;
    }

    return 0;
}
