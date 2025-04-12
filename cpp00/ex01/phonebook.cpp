#include "phonebook.hpp"

int	replace_old_contact(Contact contact[MAX_CONTACTS])
{
	// Replace the oldest contact
	int oldest = 0;

	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (contact[i].get_time() < contact[oldest].get_time())
			oldest = i;
	}
	return (oldest);
}

Phonebook::Phonebook()
{
	_contact_count = 0;
}

Phonebook::~Phonebook()
{
}

void Phonebook::add_contact(std::string first_name, std::string last_name, std::string nickname,
							std::string phone_number, std::string darkest_secret)
{
	if (_contact_count < MAX_CONTACTS)
	{
		_contact[_contact_count] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
		_contact_count++;
	}
	else
	{
		int oldest = replace_old_contact(_contact);
		_contact[oldest] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	}
}

int Phonebook::get_contact_count()
{
	return (_contact_count);
}
