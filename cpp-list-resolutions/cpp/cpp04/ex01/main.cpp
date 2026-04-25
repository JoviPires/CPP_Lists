#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Subject test ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << "=== Array test ===" << std::endl;

    Animal* animals[10];

    for (int k = 0; k < 5; k++)
        animals[k] = new Dog();
    for (int k = 5; k < 10; k++)
        animals[k] = new Cat();

    for (int k = 0; k < 10; k++)
        delete animals[k];

    std::cout << std::endl;
    std::cout << "=== Deep copy test Dog ===" << std::endl;

    Dog originalDog;
    originalDog.setIdea(0, "Bone");
    originalDog.setIdea(1, "Run");

    Dog copiedDog(originalDog);

    std::cout << "originalDog idea[0]: " << originalDog.getIdea(0) << std::endl;
    std::cout << "copiedDog idea[0]: " << copiedDog.getIdea(0) << std::endl;

    originalDog.setIdea(0, "Sleep");

    std::cout << "After change:" << std::endl;
    std::cout << "originalDog idea[0]: " << originalDog.getIdea(0) << std::endl;
    std::cout << "copiedDog idea[0]: " << copiedDog.getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "=== Deep copy test Cat ===" << std::endl;

    Cat originalCat;
    originalCat.setIdea(0, "Fish");

    Cat copiedCat;
    copiedCat = originalCat;

    std::cout << "originalCat idea[0]: " << originalCat.getIdea(0) << std::endl;
    std::cout << "copiedCat idea[0]: " << copiedCat.getIdea(0) << std::endl;

    originalCat.setIdea(0, "Sleep");

    std::cout << "After change:" << std::endl;
    std::cout << "originalCat idea[0]: " << originalCat.getIdea(0) << std::endl;
    std::cout << "copiedCat idea[0]: " << copiedCat.getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "=== Wrong animal test ===" << std::endl;

    const WrongAnimal* wrong = new WrongCat();
    wrong->makeSound();
    delete wrong;

    return 0;
}