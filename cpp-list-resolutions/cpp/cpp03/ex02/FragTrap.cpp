#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " wants to high five!" << std::endl;
}

