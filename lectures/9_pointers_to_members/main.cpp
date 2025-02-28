#include <iostream>
#include "Sample.class.hpp"

int main(void)
{
    Sample  instance;
    Sample* instancep = &instance;  // pointer on Sample class instance

    int     Sample::*p = NULL;  // pointer on integer member of Sample class

    p = &Sample::foo;

    std::cout << "Value of member foo: " << instance.foo << std::endl;
    instance.*p = 21;  // .* operator assigns value to specific ***instance*** of class member
    std::cout << "Value of member foo set by instance: " << instance.foo << std::endl;
    instancep->*p = 42;  // same but I'm using ***pointer to instance***, not instnace
    std::cout << "Value of member foo set by pointer on instance: " << instance.foo << std::endl;


    void    (Sample::*f)(void) const;  // pointer on member function of Sample class

    f = &Sample::bar;

    (instance.*f)();  // .* operator calls member function of specific ***instance*** of class function
    (instancep->*f)();  // same but I'm using ***pointer to instance***, not instnace

    return (0);
}