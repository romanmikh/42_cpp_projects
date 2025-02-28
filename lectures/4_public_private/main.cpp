#include <iostream>
#include "Sample.class.hpp"

int main()
{
    Sample instance_of_class;

    instance_of_class.public_foo = 42;
    std::cout << "instance_of_class.public_foo: " << instance_of_class.public_foo << std::endl;
    instance_of_class.public_bar();
    
    // cannot call _privates from main (outside of class instance) - althought I can access privates in constructor and this can print things
    // instance_of_class._private_foo = 42; // error: ‘int Sample::_private_foo’ is private within this context
    // std::cout << "instance_of_class._private_foo: " << instance_of_class._private_foo << std::endl; // error: ‘int Sample::_private_foo’ is private within this context
    // instance_of_class._private_bar(); // error: ‘void Sample::_private_bar() const’ is private within this context
    
    return (0);
}