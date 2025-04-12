#include "contact.hpp"

Contact::Contact()
{
	_first_name = "";
	_last_name = "";
	_time = time(&_time);

}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname,
		std::string phone_number, std::string darkest_secret)
{
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;
	_phone_number = phone_number;
	_darkest_secret = darkest_secret;
	_time = time(&_time);
}

Contact::~Contact()
{
}

std::string	Contact::get_first_name() const
{
	return _first_name;
}

std::string	Contact::get_last_name() const
{
	return _last_name;
}

std::string	Contact::get_nickname() const
{
	return _nickname;
}

std::string	Contact::get_phone_number() const
{
	return _phone_number;
}

std::string	Contact::get_darkest_secret() const
{
	return _darkest_secret;
}

time_t	Contact::get_time() const
{
	return _time;
}
