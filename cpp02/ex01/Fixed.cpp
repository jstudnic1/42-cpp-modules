#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Constructor from int
Fixed::Fixed(const int int_value) : _fixedPointValue(int_value << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

// Constructor from float
Fixed::Fixed(const float float_value) : _fixedPointValue(roundf(float_value * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
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

// to int
int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

// to float
float Fixed::toFloat(void) const
{
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

// stream insertion operator
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
