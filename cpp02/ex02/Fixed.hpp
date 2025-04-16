#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

//
class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed(void); // Default constructor
    Fixed(const int int_value);
    Fixed(const float float_value);
    Fixed(const Fixed &src); // Copy constructor
    ~Fixed(void); // Destructor

    Fixed &operator=(const Fixed &rhs); // Assignment operator

    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt(void) const;
    float toFloat(void) const;

    // Increment/decrement operators
    Fixed &operator++(void);     // Prefix increment
    Fixed &operator--(void);     // Prefix decrement
    Fixed operator++(int);       // Postfix increment
    Fixed operator--(int);       // Postfix decrement

    // Comparison operators
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    // Min/max functions
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
