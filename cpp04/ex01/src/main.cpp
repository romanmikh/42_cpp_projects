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
    const Animal* cats[2];

    for (int i = 0; i < 2; i++) {
        cats[i] = new Cat();
        Cat* catPtr = dynamic_cast<Cat*>(const_cast<Animal*>(cats[i]));  // Downcast

        if (catPtr) {
            std::stringstream ss;
            ss << "Idea " << i;
            catPtr->getBrain()->getIdea(0) = ss.str();  // Set idea

            std::cout << "Cat " << i << " Brain address: " << catPtr->getBrain() << std::endl;
            std::cout << "Cat " << i << " First idea address: " << &(catPtr->getBrain()->getIdea(0)) << std::endl;
        }
    }

    for (int i = 0; i < 2; i++)
        delete cats[i];

    return 0;
}