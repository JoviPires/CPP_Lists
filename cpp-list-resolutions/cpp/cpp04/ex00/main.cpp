#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // imprime "Meow Meow!"
    j->makeSound(); // imprime "Woof Woof!"
    meta->makeSound(); // imprime "Generic Animal sound"

    delete meta;
    delete j;
    delete i;

    std::cout << "---- WrongAnimals ----" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    wrongCat->makeSound(); // imprime "Generic WrongAnimal sound" (não virtual)
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}