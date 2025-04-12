#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook {
private:
    Contact contacts[8];
    int contact_count;
    int oldest_index;

public:
    Phonebook();
    void add_contact(std::string first_name, std::string last_name, std::string nickname,
                     std::string phone_number, std::string darkest_secret);

    // Expose contacts for testing
    Contact get_contact(int index) const { return contacts[index]; }
};

#endif
