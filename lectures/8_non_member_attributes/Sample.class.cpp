/*
- File for defining constructor, destructor and attribute function behaviour
*/

#include <iostream>
#include "Sample.class.hpp"


Sample::Sample(void)
{
    std::cout << "Constructor called" << std::endl;
    Sample::_nbInst += 1;  // increment static=non-member attribute
    return;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    Sample::_nbInst -= 1;  // decrement static=non-member attribute
    return;
}

// cannot use "this->" pointer in static=non-member function because it isn't 'invisibly' passed (despite void)
int Sample::getNbInst(void)
{
    return Sample::_nbInst;  // return static=non-member attribute
}

int Sample::_nbInst = 0;  // initialize static=non-member attribute