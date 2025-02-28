/*
- File for defining constructor, destructor and attribute function behaviour
*/

#include <iostream>
#include "Sample.class.hpp"


// constructors & destructors don't have a return type, they're void
Sample::Sample(void)
{
    std::cout << "Constructor called" << std::endl;
    
    this->foo = 42; // this-> is a pointer to the current instance of the class. Instantiate at construction
    std::cout << "this->foo: " << this->foo << std::endl;

    this->bar();

    return;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void Sample::bar(void) // define member functions (method) here
{
    std::cout << "Member function bar called" << std::endl;
    return;
}