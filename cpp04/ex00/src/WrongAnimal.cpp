/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/WrongAnimal.hpp"

// ************************************************************************** //
//             Orthodox Canonical Constructors & Desctructors                 //
// ************************************************************************** //
WrongAnimal::WrongAnimal(void) {
    setType("Chimera 👾");
    printStr("WrongAnimal created! :D", "G");
}

// WrongAnimal::WrongAnimal(const WrongAnimal & other) : WrongAnimal() {
//     printStr("WrongAnimal " + other.getName() + " copied! :D", "B");
//     *this = other;
// }

WrongAnimal::~WrongAnimal(void){
    printStr("WrongAnimal destroyed! D:", "G");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
WrongAnimal & WrongAnimal::operator = (const WrongAnimal & other) {
    if (this != &other)
        this->_type = other.getType();
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
std::string WrongAnimal::getType(void) const {
    return _type;
}

void        WrongAnimal::setType(std::string type) {
    this->_type = type;
}

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
void        WrongAnimal::makeSound(void) const {
    printStr(getType() + " says: *skibbidi*", "G");
}
// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
