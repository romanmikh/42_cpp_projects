/*
- File for defining constructor, destructor and attribute function behaviour
*/

#include <iostream>
#include "Sample.class.hpp"


Sample::Sample(float const f) : pi(f), qd(42) // initialisation list, *not* assignment to f. f given in main
{
    std::cout << "Constructor called" << std::endl;
    return;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void Sample::bar(void) const
{
    std::cout << "this->pi = " << this->pi << std::endl;
    std::cout << "this->qd = " << this->qd << std::endl;

    // bar() is const, so cannot modify the class instance of qd
    // this->qd = 0; // error: assignment of member ‘Sample::qd’ in read-only object

    return;
}