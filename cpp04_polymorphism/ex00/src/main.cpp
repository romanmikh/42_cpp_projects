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
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();
    std::cout << std::endl;

    printStr("meta is a " + meta->getType(), "G");
    printStr("i is a " + i->getType(), "R");
    printStr("j is a " + j->getType(), "B");
    std::cout << std::endl;

    meta->makeSound();
    i->makeSound();
    j->makeSound();
    std::cout << std::endl;

    delete meta;
    delete i;
    delete j;

    return 0;
}

// int main(void)
// {
//     const WrongAnimal* meta = new WrongAnimal();
//     const WrongAnimal* i = new WrongCat();
//     std::cout << std::endl;

//     printStr("meta is a " + meta->getType(), "G");
//     printStr("i is a " + i->getType(), "R");
//     std::cout << std::endl;

//     meta->makeSound();
//     i->makeSound();
//     std::cout << std::endl;

//     delete meta;
//     delete i;
//     std::cout << std::endl << std::endl;

//     printStr("BUT if we instantiate WrongCat without animal:", "R");

//     const WrongCat* j = new WrongCat();
//     j->makeSound();
//     printStr("it doesn't inherit Animal's makeSound()", "R");
//     std::cout << std::endl;

//     delete j;

//     return 0;
// }