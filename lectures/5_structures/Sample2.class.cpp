/*
- File for defining constructor, destructor and attribute function behaviour
*/

#include <iostream>
#include "Sample2.class.hpp"


Sample2::Sample2(void)
{
    std::cout << "Constructor called" << std::endl;
    return;
}

Sample2::~Sample2(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}
