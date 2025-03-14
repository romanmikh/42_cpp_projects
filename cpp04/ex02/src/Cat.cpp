/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/Cat.hpp"

// ************************************************************************** //
//             Orthodox Canonical Constructors & Desctructors                 //
// ************************************************************************** //
Cat::Cat(void) : Animal(), _brain(new Brain()) {
    setType("Cat 🐱");
    printStr(getType() + " created! :D", "R");
    printStr(getType() + " grew a brain! 🧠\n", "P");
}

Cat::Cat(const Cat & other) : Animal(), _brain(new Brain(*other._brain)) {
    printStr(getType() + " copied! :D", "R");
    *this = other;
}

Cat::~Cat(void){
    delete this->_brain;
    printStr(getType() + " destroyed its own brain 🧠", "P");
    printStr(getType() + " destroyed! D:", "R");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
Cat & Cat::operator = (const Cat & other) {
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
Brain*     Cat::getBrain(void) const {
    return this->_brain;
}

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
void       Cat::makeSound(void) const {
    printStr(getType() + " says: *miau miau*", "R");
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
