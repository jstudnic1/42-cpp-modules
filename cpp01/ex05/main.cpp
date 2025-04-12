#include "Harl.hpp"

int main() {
    Harl karen; // Create a Harl object

    std::cout << "--- Testing DEBUG ---" << std::endl;
    karen.complain("DEBUG");

    std::cout << "--- Testing INFO ---" << std::endl;
    karen.complain("INFO");

    std::cout << "--- Testing WARNING ---" << std::endl;
    karen.complain("WARNING");

    std::cout << "--- Testing ERROR ---" << std::endl;
    karen.complain("ERROR");

    std::cout << "--- Testing an invalid level ---" << std::endl;
    karen.complain("SOME_OTHER_NONSENSE");

    return 0;
}
