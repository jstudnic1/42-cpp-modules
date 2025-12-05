#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span {
private:
    unsigned int N;
    std::vector<int> vec;

public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    // TODO: Implement addNumber
    void addNumber(int n);

    // TODO: Implement addNumber (range)
    template <typename InputIterator>
    void addNumber(InputIterator begin, InputIterator end) {
        // Your implementation here
        unsigned int dist = std::distance(begin, end);
        if (dist > this->N)
            throw FullException();
        this->N -= dist;
        this->vec.insert(this->vec.end(), begin, end);
    }

    // TODO: Implement shortestSpan and longestSpan
    unsigned int shortestSpan();
    unsigned int longestSpan();

    // TODO: Define custom exceptions
	class FullException : public std::exception {
		public:
		const char *what() const throw() {
			return "Span is full";
		}
	};
	class NotEnoughNumbersException : public std::exception {
		public:
		const char *what() const throw() {
			return "Not enough numbers";
		}
	};
};

#endif
