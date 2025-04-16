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
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
