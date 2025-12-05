#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Span.hpp"

int main() {
    // Subject Test
    std::cout << "--- Subject Test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Exception Test
    std::cout << "\n--- Exception Test ---" << std::endl;
    try {
        Span sp = Span(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // Should throw
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        Span sp = Span(5);
        sp.addNumber(1);
        sp.shortestSpan(); // Should throw
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    // Range Test
    std::cout << "\n--- Range Test (10,000 numbers) ---" << std::endl;
    try {
        Span sp(10000);
        std::vector<int> v;
        std::srand(std::time(NULL));
        for (int i = 0; i < 10000; ++i) {
            v.push_back(std::rand());
        }
        sp.addNumber(v.begin(), v.end());
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
