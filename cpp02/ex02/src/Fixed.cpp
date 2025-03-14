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
Fixed::Fixed(void) : _val(0) {}

Fixed::Fixed(const Fixed &other) {
    this->_val = other.getRawBits();
}

Fixed::Fixed(const int val) : _val(val << this->_fracBits) {}

Fixed::Fixed(const float val) : _val(roundf(val * (1 << this->_fracBits))) {}


Fixed::~Fixed(void){}

// ************************************************************************** //
//                               Operators                                    //
// ************************************************************************** //
Fixed &Fixed::operator = (const Fixed & other) {
    if (this != & other)
        this->_val = other.getRawBits();
    return (*this);
}

bool Fixed::operator > (const Fixed & other) const {
    return (this->_val > other.getRawBits());
}

bool Fixed::operator < (const Fixed & other) const {
    return (this->_val < other.getRawBits());
}

bool Fixed::operator >= (const Fixed & other) const {
    return (this->_val >= other.getRawBits());
}

bool Fixed::operator <= (const Fixed & other) const {
    return (this->_val <= other.getRawBits());
}

bool Fixed::operator == (const Fixed & other) const {
    return (this->_val == other.getRawBits());
}

bool Fixed::operator != (const Fixed & other) const {
    return (this->_val != other.getRawBits());
}

Fixed Fixed::operator + (const Fixed & other) const {
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator - (const Fixed & other) const {
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator * (const Fixed & other) const {
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator / (const Fixed & other) const {
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed & Fixed::operator ++ (void) {
    this->_val++;
    return (*this);
}

Fixed & Fixed::operator -- (void) {
    this->_val--;
    return (*this);
}

Fixed Fixed::operator ++ (int) {
    Fixed tmp(*this);
    ++(this->_val);
    return (tmp);
}

Fixed Fixed::operator -- (int) {
    Fixed tmp(*this);
    --(this->_val);
    return (tmp);
}

Fixed & Fixed::min(Fixed & a, Fixed & b) {
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b) {
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b) {
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
int     Fixed::getRawBits(void) const {
    return (this->_val);
}

void    Fixed::setRawBits(int const raw) {
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