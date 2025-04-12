#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed(void); // Default constructor
    Fixed(const Fixed &src); // Copy constructor
    ~Fixed(void); // Destructor

    Fixed &operator=(const Fixed &rhs); // Assignment operator

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
