#include <iostream>
#include "Sample.class.hpp"

int f0(void)
{
    Sample instance;

    std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;

    return (0);
}

int f1(void)
{
    Sample instance;

    std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
    f0();

    return (0);
}

int main(void)
{
    Sample instance;

    std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
    f1();
    std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;

    return (0);
}