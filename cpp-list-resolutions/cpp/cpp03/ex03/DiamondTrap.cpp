#include "DiamondTrap.hpp"
#include <iostream>

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), name("default") {
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;

    std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Name constructor
DiamondTrap::DiamondTrap(const std::string& name) 
: ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name(name) {
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;

    std::cout << "DiamondTrap constructor called" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

// Assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other); // copia atributos herdados
        this->name = other.name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

// attack() usa o ScavTrap
void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

// whoAmI()
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->name
              << ", ClapTrap name: " << this->_name << std::endl;
}