#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits;
}

Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(n * (1 << _fractionalBits));
}

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat(void) const {
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const {
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_value + other._value);
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_value - other._value);
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.setRawBits((this->_value * other._value) >> _fractionalBits);
    return (result);
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result.setRawBits((this->_value << _fractionalBits) / other._value);
    return (result);
}

// Increment / Decrement
Fixed& Fixed::operator++() {
    _value++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _value++;
    return (temp);
}

Fixed& Fixed::operator--() {
    _value--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _value--;
    return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return ((a < b) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return ((a > b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return ((a > b) ? a : b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
    out << obj.toFloat();
    return (out);
}