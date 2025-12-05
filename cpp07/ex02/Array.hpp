#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstdlib> // for size_t

template <typename T>
class Array {
private:
    T *_arr;
    unsigned int _size;
public:
    // Construction with no parameter
    Array();

    // Construction with an unsigned int n
    Array(unsigned int n);

    // Copy constructor
    Array(const Array &other);

    // Assignment operator
    Array &operator=(const Array &other);

    // Destructor
    ~Array();

    // Subscript operator
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;

    // size() function
    unsigned int size() const;

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#include "Array.tpp"

#endif
