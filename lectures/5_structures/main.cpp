#include <iostream>
#include "Sample1.class.hpp"
#include "Sample2.class.hpp"

int main()
{
    Sample1 instance_of_Sample1; // struct conpiles just fine, because public by default
    Sample2 instance_of_Sample2; // error: ‘Sample2::Sample2()’ is private (even though we didn't specify)

    return (0);
}