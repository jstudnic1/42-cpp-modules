#ifndef CONTACT_H
# define CONTACT_H
#include <ctime>
#include <string>

class Contact
{

	private:
			std::string _first_name;
			std::string _last_name;
			std::string _nickname;
			std::string _phone_number;
			std::string _darkest_secret;
			time_t _time;

	public:
			Contact();
			~Contact();
			Contact(std::string first_name, std::string last_name, std::string nickname,
					std::string phone_number, std::string darkest_secret);

			std::string get_first_name() const;
			std::string get_last_name() const;
			std::string get_nickname() const;
			std::string get_phone_number() const;
			std::string get_darkest_secret() const;

			time_t get_time() const;

};
#endif
