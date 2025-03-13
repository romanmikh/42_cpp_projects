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

Fixed::Fixed(const Fixed & other) {
    printRM("Copy constructor called :D", "Y");
    this->_val = other.getRawBits();
}

Fixed::~Fixed(void) {
    printRM("Destructor called :(", "G");
}

// ************************************************************************** //
//                               Operators                                    //
// ************************************************************************** //
/*
    Fixed &(1) Fixed(2)::operator(3) = (const Fixed & other)(4)
    - (1) & pegged to 1st Fixed, returning a ref to Fixed to allow (a=b=c)
          using ref instead of copy (without &) to avoid temp copy only
          *this (value) ~= Fixed & (ref) so we return a value by ref
    - (2) Fixed(2) is the class that the operator belongs to
    - (3) operator to overload
    - (4) const Fixed & other is the unchanged object passed to the operator
*/
Fixed & Fixed::operator = (const Fixed & other) {
    printRM("Copy assignment operator overload called :D", "P");
    if (this != &other)
        this->_val = other.getRawBits();
    return (*this); 
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
