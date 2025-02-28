/*
- File for defining constructor, destructor and attribute function behaviour
*/

#include <iostream>
#include "Sample.class.hpp"


Sample::Sample(int v)
{
    std::cout << "Constructor called" << std::endl;
    return;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

int Sample::getFoo(void) const
{
    return this->_foo;
}

// using == compares addresses, so identical instances will give !=. This is our workaround:
int Sample::compare(Sample * other) const  
{
    if (this->_foo < other->getFoo())
        return -1;
    else if (this->_foo > other->getFoo())
        return 1;
    return 0;
}