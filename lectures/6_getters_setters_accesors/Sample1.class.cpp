/*
- File for defining constructor, destructor and attribute function behaviour
*/

#include <iostream>
#include "Sample1.class.hpp"


Sample1::Sample1(void)
{
    std::cout << "Constructor called" << std::endl;
    return;
}

Sample1::~Sample1(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

int Sample1::getFoo(void) const  // grants read-only access to _foo
{
    return this->_foo;
}

void Sample1::setFoo(int v)  // grants write access to _foo (no const keyword)
{
    if (v >= 0)
        this->_foo = v;
    return;
}