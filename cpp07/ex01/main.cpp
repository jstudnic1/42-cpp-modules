#include <iostream>
#include "iter.hpp"

template <typename T>
void print(const T &x) {
    std::cout << x << " ";
}

template <typename T>
void increment(T &x) {
    x++;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = 5;

    std::cout << "Original int array: ";
    ::iter(arr, len, print<int>);
    std::cout << std::endl;

    std::cout << "Incrementing..." << std::endl;
    ::iter(arr, len, increment<int>);

    std::cout << "Modified int array: ";
    ::iter(arr, len, print<int>);
    std::cout << std::endl;

    std::string strArr[] = {"one", "two", "three"};
    size_t strLen = 3;

    std::cout << "String array: ";
    ::iter(strArr, strLen, print<std::string>);
    std::cout << std::endl;

    const int constArr[] = {10, 20, 30};
    std::cout << "Const int array: ";
    ::iter(constArr, 3, print<int>);
    std::cout << std::endl;

    return 0;
}
