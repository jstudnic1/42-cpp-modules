#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include "contact.hpp"

#define MAX_CONTACTS 8

class Phonebook
{
	private:
		int _contact_count;
	public:
		Contact _contact[MAX_CONTACTS];
		Phonebook();
		~Phonebook();
		void	add_contact(std::string first_name, std::string last_name, std::string nickname,
							std::string phone_number, std::string darkest_secret);
		int 	get_contact_count();
	};

int	replace_old_contact(Contact contact[MAX_CONTACTS]);

#endif
