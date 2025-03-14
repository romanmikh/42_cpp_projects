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
}

Dog::Dog(const Dog & other) : Animal(), _brain(NULL) {
    printStr(getType() + " copied (deeply)! :D", "B");
    if (_brain) {
        delete _brain;
    }
    if (other._brain) {
        _brain = new Brain(*other._brain);
    }
}

Dog::~Dog(void){
    delete this->_brain;
    printStr(getType() + " destroyed! D:", "B");
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
    printStr(getType() + " brain assigned (deeply)! :D", "B");
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
