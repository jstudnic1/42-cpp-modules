#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &src) : _fixedPointValue(src._fixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

// Get raw bits
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

// Set raw bits
void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}
