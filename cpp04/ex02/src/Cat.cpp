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
    printStr(getType() + " created! :D", "P");
}

Cat::Cat(const Cat & other) : Animal(), _brain(NULL) {
    printStr(getType() + " copied (deeply)! :D", "P");
    if (_brain) {
        delete _brain;
    }
    if (other._brain) {
        _brain = new Brain(*other._brain);
    }
}

Cat::~Cat(void){
    delete this->_brain;
    printStr(getType() + " destroyed! D:", "P");
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
    printStr(getType() + " brain assigned (deeply)! :D", "B");
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
    printStr(getType() + " says: *miau miau*", "P");
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
