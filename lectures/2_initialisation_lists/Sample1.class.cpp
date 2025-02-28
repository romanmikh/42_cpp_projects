/*
- File for defining constructor, destructor and attribute function behaviour
*/

#include <iostream>
#include "Sample1.class.hpp"


// constructors & destructors don't have a return type, they're void
Sample1::Sample1(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3)  // initialisation list
{
    std::cout << "Constructor called" << std::endl;
    std::cout << "this->a1: " << this->a1 << std::endl;
    std::cout << "this->a2: " << this->a2 << std::endl;
    std::cout << "this->a3: " << this->a3 << std::endl;

    return;
}

Sample1::~Sample1(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}
