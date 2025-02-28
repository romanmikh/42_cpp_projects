/*
- File for defining constructor, destructor and attribute function behaviour
*/

#include <iostream>
#include "Sample.class.hpp"


Sample::Sample(void)  // in constructor we include both public and private attributes
{
    std::cout << "Constructor called" << std::endl;
    
    this->public_foo = 0;
    std::cout << "this->public_foo: " << this->public_foo << std::endl;
    this->_private_foo = 0;
    std::cout << "this->_private_foo: " << this->_private_foo << std::endl;

    this->public_bar();
    this->_private_bar();

    return;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void Sample::public_bar(void) const
{
    std::cout << "Member function public_bar called" << std::endl;
    return;
}

void Sample::_private_bar(void) const
{
    std::cout << "Member function _private_bar called" << std::endl;
    return;
}