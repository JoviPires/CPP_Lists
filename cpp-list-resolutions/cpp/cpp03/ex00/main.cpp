#include "ClapTrap.hpp"
int main() {
    ClapTrap ct1("Clap1");
    ClapTrap ct2(ct1);
    ClapTrap ct3;

    ct3 = ct1;

    ct1.attack("Target1");
    ct2.takeDamage(5);
    ct3.beRepaired(3);

    return (0);
}
