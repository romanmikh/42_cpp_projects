/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/Dog.hpp"

// ************************************************************************** //
//             Orthodox Canonical Constructors & Desctructors                 //
// ************************************************************************** //
Dog::Dog(void) : Animal(), _brain(new Brain()) {
    setType("Dog 🐶");
    printStr(getType() + " created! :D", "B");
    printStr(getType() + " grew a brain! 🧠\n", "B");
}

Dog::Dog(const Dog & other) : Animal(), _brain(new Brain(*other._brain)) {
    printStr(getType() + " copied! :D", "B");
    *this = other;
}

Dog::~Dog(void){
    delete this->_brain;
    printStr(getType() + " destroyed its own brain 🧠", "P");
    printStr(getType() + " destroyed! D:", "R");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
Dog & Dog::operator = (const Dog & other) {
    if (this != &other) {
        this->_type = other.getType();
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
Brain*     Dog::getBrain(void) const {
    return this->_brain;
}

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
void       Dog::makeSound(void) const {
    printStr(getType() + " says: *miau miau*", "B");
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
