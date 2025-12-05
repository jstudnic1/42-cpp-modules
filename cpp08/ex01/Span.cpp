#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span(unsigned int N) {
    this->N = N;
}

Span::Span(const Span &other) {
    *this = other;
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        this->N = other.N;
        this->vec = other.vec;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (this->N == 0)
        throw FullException();
    this->N--;
    this->vec.push_back(n);
}

unsigned int Span::shortestSpan() {
    if (this->vec.size() < 2)
        throw NotEnoughNumbersException();
    std::vector<int> sorted = this->vec;
    std::sort(sorted.begin(), sorted.end());
    unsigned int shortest = static_cast<unsigned int>(sorted[1] - sorted[0]);
    for (size_t i = 1; i < sorted.size() - 1; i++) {
        if (static_cast<unsigned int>(sorted[i + 1] - sorted[i]) < shortest)
            shortest = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
    }
    return shortest;
}

unsigned int Span::longestSpan() {
    if (this->vec.size() < 2)
        throw NotEnoughNumbersException();
    int minVal = *std::min_element(this->vec.begin(), this->vec.end());
    int maxVal = *std::max_element(this->vec.begin(), this->vec.end());
    return maxVal - minVal;
}
