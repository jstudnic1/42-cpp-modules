#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // Test with std::vector
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try {
        std::cout << "Searching for 20 in vector: ";
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << *it << std::endl; // Should print 20
    } catch (std::exception &e) {
        std::cout << "Not found" << std::endl;
    }

    // Test with std::list
    std::list<int> l;
    l.push_back(100);
    l.push_back(200);
    l.push_back(300);

    try {
        std::cout << "Searching for 400 in list: ";
        std::list<int>::iterator it = easyfind(l, 400);
        std::cout << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}
