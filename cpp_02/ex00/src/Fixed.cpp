/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Utils.hpp"

// ************************************************************************** //
//                      Constructors & Desctructors                           //
// ************************************************************************** //
Fixed::Fixed(void) {
    printRM("Default constructor called :D", "G");
    this->_val = 0;
}

Fixed::Fixed(const Fixed &other) {
    printRM("Copy constructor called :D", "G");
    this->_val = other.getRawBits();
}

Fixed &Fixed::operator = (const Fixed &other) {
    printRM("Copy assignment operator overload called :D", "G");
    if (this != &other)
        this->_val = other.getRawBits();
    return (*this);
}

Fixed::~Fixed(void) {
    printRM("Destructor called :(", "G");
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
int Fixed::getRawBits(void) const {
    printRM("getRawBits member function called");
    return (this->_val);
}

void    Fixed::setRawBits(int const raw) {
    printRM("setRawBits member function called");
    this->_val = raw;
}
// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //
