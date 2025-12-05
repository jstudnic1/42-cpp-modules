#include <iostream>
#include <cstdlib>
#include "Array.hpp"

struct s_test {
	int a;
	char b;
};

std::ostream& operator<<(std::ostream& os, const s_test& t) {
	os << t.a << t.b;
	return os;
}

template <typename T>
void printArray(const Array<T>& arr, const std::string& name) {
	std::cout << name << " size: " << arr.size() << std::endl;
	std::cout << name << ": ";
	for (unsigned int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main(int, char**)
{
	std::cout << "\033[33m" << std::endl << "Empty Array" << "\033[0m" << std::endl;
	Array<int> emptyArray;
	printArray(emptyArray, "emptyArray");

	std::cout << "\033[33m" << std::endl << "Out of Bounds" << "\033[0m" << std::endl;
	try {
		std::cout << "emptyArray[5]: " << emptyArray[5] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[33m" << std::endl << "Int Array" << "\033[0m" << std::endl;
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = i;
	}
	printArray(intArray, "intArray");

	std::cout << "\033[33m" << std::endl << "Double Array" << "\033[0m" << std::endl;
	Array<double> doubleArray(10);
	for (unsigned int i = 0; i < doubleArray.size(); i++) {
		doubleArray[i] = i / 2.0;
	}
	printArray(doubleArray, "doubleArray");

	std::cout << "\033[33m" << std::endl << "Copy Constructor using int array" << "\033[0m" << std::endl;
	Array<int> intArrayCopy(intArray);
	printArray(intArrayCopy, "intArrayCopy");

	std::cout << "\033[33m" << std::endl << "Assignment Operator using double array" << "\033[0m" << std::endl;
	Array<double> doubleArrayAssignment = doubleArray;
	printArray(doubleArrayAssignment, "doubleArrayAssignment");

	std::cout << "\033[33m" << std::endl << "Const Instance" << "\033[0m" << std::endl;
	const Array<int> constIntArray(intArray);
	printArray(constIntArray, "constIntArray");

	std::cout << "\033[33m" << std::endl << "Complex Array Type from own struct" << "\033[0m" << std::endl;
	Array<s_test> structArray(6);
	for (unsigned int i = 0; i < structArray.size(); i++) {
		structArray[i].a = i;
		structArray[i].b = 'a' + i;
	}
	printArray(structArray, "structArray");

	return (0);
}
