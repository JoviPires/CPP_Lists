#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "===== SUBJECT TEST =====" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << "===== ARRAY TEST =====" << std::endl;

    Animal* animals[10];

    for (int i = 0; i < 5; i++) {
        animals[i] = new Dog();
    }
    for (int i = 5; i < 10; i++) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 10; i++) {
        delete animals[i];
    }

    std::cout << std::endl;
    std::cout << "===== DEEP COPY TEST DOG =====" << std::endl;

    Dog originalDog;
    originalDog.setIdea(0, "I want a bone");
    originalDog.setIdea(1, "I want to run");

    Dog copiedDog(originalDog);

    std::cout << "originalDog idea[0]: " << originalDog.getIdea(0) << std::endl;
    std::cout << "copiedDog idea[0]: " << copiedDog.getIdea(0) << std::endl;

    originalDog.setIdea(0, "I want to sleep");

    std::cout << "After changing originalDog:" << std::endl;
    std::cout << "originalDog idea[0]: " << originalDog.getIdea(0) << std::endl;
    std::cout << "copiedDog idea[0]: " << copiedDog.getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "===== DEEP COPY TEST CAT =====" << std::endl;

    Cat originalCat;
    originalCat.setIdea(0, "I want fish");

    Cat copiedCat;
    copiedCat = originalCat;

    std::cout << "originalCat idea[0]: " << originalCat.getIdea(0) << std::endl;
    std::cout << "copiedCat idea[0]: " << copiedCat.getIdea(0) << std::endl;

    originalCat.setIdea(0, "I want to sleep");

    std::cout << "After changing originalCat:" << std::endl;
    std::cout << "originalCat idea[0]: " << originalCat.getIdea(0) << std::endl;
    std::cout << "copiedCat idea[0]: " << copiedCat.getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "===== WRONG ANIMAL TEST =====" << std::endl;

    const WrongAnimal* wrong = new WrongCat();
    wrong->makeSound();
    delete wrong;

    return 0;
}