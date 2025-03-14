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
        printStr(cats[i]->getBrain()->getIdea(0));
        printStr(cats[i]->getBrain()->getIdea(1));
        std::cout << "I'm cat #" << i << ". Address of my first idea: " << 
                    &cats[i]->getBrain()->getIdea(0) << std::endl << std::endl;
    }

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
        printStr(dogs[i]->getBrain()->getIdea(0));
        printStr(dogs[i]->getBrain()->getIdea(1));
        std::cout << "I'm dog #" << i << ". Address of my first idea: " << 
                    &dogs[i]->getBrain()->getIdea(0) << std::endl << std::endl;
    }

    printStr("---------------------------------------------------------------");
    printStr("---------------------- Killing Animals ------------------------");
    printStr("---------------------------------------------------------------");
    
    for (int i = 0; i < numAnimals; i++)
        delete animals[i];

    for (int i = 0; i < maxCats; i++)
        delete cats[i];

    for (int i = 0; i < maxDogs; i++)
        delete dogs[i];

    return 0;
}
