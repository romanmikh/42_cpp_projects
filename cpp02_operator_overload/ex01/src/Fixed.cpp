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
Fixed::Fixed(void) : _val(0) {
    printRM("Default constructor called :D", "G");
}

Fixed::Fixed(const Fixed &other) {
    printRM("Copy constructor called :D", "Y");
    this->_val = other.getRawBits();
}

Fixed &Fixed::operator = (const Fixed &other) {
    printRM("Copy assignment operator overload called :D", "P");
    if (this != &other)
        this->_val = other.getRawBits();
    return (*this);
}

Fixed::~Fixed(void) {
    printRM("Destructor called :(", "G");
}

// specific to ex01
Fixed::Fixed(const int val) : _val(val << this->_fracBits) {
    printRM("toInt constructor called", "C");
}

Fixed::Fixed(const float val) : _val(roundf(val * (1 << this->_fracBits))) {
    printRM("toFloat constructor called :D", "C");
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
int     Fixed::getRawBits(void) const {
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
/*
  - fixed point numbers store real values as integers scaled by a power of 2
  - fixed = (float or int) * (2^fracBits)
  - _fracBits = 8 -> 1 stored as 256, 0.5 as 128, 0.25 as 64, etc.
  - 1 << 8 shifts by 8 bits to the left => 1 -> 256
*/
float   Fixed::toFloat(void) const {
    return ((float)this->_val / (1 << this->_fracBits));
}

int     Fixed::toInt(void) const {
    return (this->_val >> this->_fracBits);
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
/*
  - 1st & because std::ostream cannot be copied -> compilation error
  - 2nd & because we don't want to copy the stream, just use it
  - 3rd & because we avoid unnecessary calls to copy constructors -> efficiency
*/
std::ostream & operator << (std::ostream & out, const Fixed & fixed) {
    out << fixed.toFloat();
    return (out);
}