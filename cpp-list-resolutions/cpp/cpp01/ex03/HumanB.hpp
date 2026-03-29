#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *weapon; //ponteiro pois humanB pode não ter arma, e nesse caso o ponteiro deve ser nulo e depois ser setado com a arma
public:
    HumanB(const std::string &name);
    void setWeapon(Weapon &weapon);
    void attack(void) const;
};

#endif