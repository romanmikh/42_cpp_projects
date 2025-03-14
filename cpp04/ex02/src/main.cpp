/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Utils.hpp"

int main(void)
{
    
    // Animal* animal = new Animal();  
    /* 
        - error: unimplemented pure virtual method 'makeSound' in 'Animal'
        - Animal is an abstract class, so it can't be instantiated
        - it can only be used as a base class for other classes
        - so derived classes like Dog and Cat work just fine
        - because they implement their own makeSound() methods
    */ 

    int numAnimals = 4;

    printStr("---------------------------------------------------------------");
    printStr("------------------- Testing Animals Array ---------------------");
    printStr("---------------------------------------------------------------");

    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals / 2; i++)
        animals[i] = new Cat();

    for (int i = numAnimals / 2; i < numAnimals; i++)
        animals[i] = new Dog();

    for (int i = 0; i < numAnimals; i++)
        animals[i]->makeSound();

    printStr("---------------------------------------------------------------");
    printStr("--------------------- Testing Cat Brains ----------------------");
    printStr("---------------------------------------------------------------");

    int maxCats = numAnimals / 2;
    Cat* cats[maxCats];

    for (int i = 0; i < maxCats; i++)
        cats[i] = new Cat();

    for (int i = 0; i < maxCats; i++) {
        cats[i]->getBrain()->setIdea("I am a cat...", 0);
        cats[i]->getBrain()->setIdea("...I am still a cat", 1);
        std::cout << "Idea #" << 0 << ": " << cats[i]->getBrain()->getIdea(0) << std::endl;
        std::cout << "Idea #" << 1 << ": " << cats[i]->getBrain()->getIdea(1) << std::endl;
        std::cout << "I'm cat #" << i << ". Address of my 0th idea: " << &cats[i]->getBrain()->getIdea(0) << std::endl << std::endl;
    }

    Cat kit;
    kit = *cats[0];
    kit.getBrain()->setIdea("I am a kitten...", 0);
    std::cout << "Idea #0: " << kit.getBrain()->getIdea(0) << std::endl;
    std::cout << "Address of kit's 0th idea: " << &kit.getBrain()->getIdea(0) << std::endl << std::endl;

    std::cout << &cats[0]->getBrain()->getIdea(0) << 
    ((&cats[0]->getBrain()->getIdea(0)) == &cats[1]->getBrain()->getIdea(0) ? " = " : " != ") 
    << &cats[1]->getBrain()->getIdea(0) <<
    ((&cats[1]->getBrain()->getIdea(0)) == &kit.getBrain()->getIdea(0) ? " = " : " != ") 
    << &kit.getBrain()->getIdea(0) << " => deep copies created!" << std::endl << std::endl;

    printStr("---------------------------------------------------------------");
    printStr("--------------------- Testing Dog Brains ----------------------");
    printStr("---------------------------------------------------------------");

    int maxDogs = numAnimals / 2;
    Dog* dogs[maxCats];

    for (int i = 0; i < maxDogs; i++)
        dogs[i] = new Dog();

    for (int i = 0; i < maxDogs; i++) {
        dogs[i]->getBrain()->setIdea("I am a dog...", 0);
        dogs[i]->getBrain()->setIdea("...I am still a dog", 1);
        std::cout << "Idea #" << 0 << ": " << dogs[i]->getBrain()->getIdea(0) << std::endl;
        std::cout << "Idea #" << 1 << ": " << dogs[i]->getBrain()->getIdea(1) << std::endl;
        std::cout << "I'm dog #" << i << ". Address of my 0th idea: " << &dogs[i]->getBrain()->getIdea(0) << std::endl << std::endl;
    }

    Dog pup;
    pup = *dogs[0];
    pup.getBrain()->setIdea("I am a pup...", 0);
    std::cout << "Idea #0: " << pup.getBrain()->getIdea(0) << std::endl;
    std::cout << "Address of pup's 0th idea: " << 
                    &pup.getBrain()->getIdea(0) << std::endl << std::endl;

    std::cout << &dogs[0]->getBrain()->getIdea(0) << 
    ((&dogs[0]->getBrain()->getIdea(0)) == &dogs[1]->getBrain()->getIdea(0) ? " = " : " != ") 
    << &dogs[1]->getBrain()->getIdea(0) <<
    ((&dogs[1]->getBrain()->getIdea(0)) == &pup.getBrain()->getIdea(0) ? " = " : " != ") 
    << &pup.getBrain()->getIdea(0) << " => deep copies created!" << std::endl << std::endl;

    printStr("---------------------------------------------------------------");
    printStr("---------------------- Killing Animals ------------------------");
    printStr("---------------------------------------------------------------");
    
    for (int i = 0; i < numAnimals; i++)
        delete animals[i];

    for (int i = 0; i < maxCats; i++)
        delete cats[i];

    for (int i = 0; i < maxDogs; i++)
        delete dogs[i];

    // delete kit;  // don't need these bc assigned by overloaded = operator
    // delete pup;  // they're wiped when they go out of scope (end of main)

    return 0;
}
