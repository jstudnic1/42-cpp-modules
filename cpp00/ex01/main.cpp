#include <iostream>
#include <iomanip>
#include "contact.hpp"
#include "phonebook.hpp"
#include "main.hpp"

int main() {
    Phonebook phonebook;

    // Add test contacts
    phonebook.add_contact("John", "Doe", "JD", "123456789", "I am John Doe");
    phonebook.add_contact("Jane", "Doe", "Jane", "987654321", "I am Jane Doe");

    // Print contacts manually (testing only)
    std::cout << "\nPhonebook Records:\n";
    std::cout << std::setw(10) << "Index" << " | "
              << std::setw(10) << "First Name" << " | "
              << std::setw(10) << "Last Name" << " | "
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < 2; i++) {  // Change this value based on test cases
        Contact c = phonebook.get_contact(i);  // You might need to implement get_contact() in Phonebook

        std::cout << std::setw(10) << i << " | "
                  << std::setw(10) << (c.get_first_name().length() > 10
                                       ? c.get_first_name().substr(0, 9) + "."
                                       : c.get_first_name()) << " | "
                  << std::setw(10) << (c.get_last_name().length() > 10
                                       ? c.get_last_name().substr(0, 9) + "."
                                       : c.get_last_name()) << " | "
                  << std::setw(10) << (c.get_nickname().length() > 10
                                       ? c.get_nickname().substr(0, 9) + "."
                                       : c.get_nickname()) << std::endl;
    }

    return 0;
}
