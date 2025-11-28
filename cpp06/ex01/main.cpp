#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data data;
	data.name = "Test Data";
	data.value = 42;
	data.price = 19.99;

	std::cout << "Original Data Address: " << &data << std::endl;
	std::cout << "Name: " << data.name << ", Value: " << data.value << ", Price: " << data.price << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized: " << raw << std::endl;

	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data Address: " << ptr << std::endl;

	if (ptr == &data)
	{
		std::cout << "Success: Pointers match!" << std::endl;
		std::cout << "Name: " << ptr->name << ", Value: " << ptr->value << ", Price: " << ptr->price << std::endl;
	}
	else
	{
		std::cout << "Error: Pointers do not match!" << std::endl;
	}

	return 0;
}
