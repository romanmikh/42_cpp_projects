/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

/*
  - this exercise is about dynamic_cast<target-type>(expression)
  - it converts a pointer or reference from a base class to a derived class	
  - pointer can be cast directly (NULL if cast fails)
  - reference must be casted to a pointer first (+ assigned to variable)
  - if we don't castot pointer first, reference failure throws std::bad_cast 
    (not allowed because it needs #include <typeinfo>)
*/

Base* generate(void) {
    int random = rand() % 3;
    Base *base = NULL;

    if (random == 0) {
        base = new A();
    } else if (random == 1) {
        base = new B();
    } else {
        base = new C();
    }
    return base;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Identified by pointer: ";
        printStr("A", "P");
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Identified by pointer: ";
        printStr("B", "P");
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Identified by pointer: ";
        printStr("C", "P");
    }
    else {
        printStr("Error: Could not identify the pointer", "R");
    }
}

// void identify(Base& p) {
//     if (A* a = dynamic_cast<A*>(&p)) {
//         (void)a;
//         std::cout << "Identified by reference: ";
//         printStr("A", "P");
//     } else if (B* b = dynamic_cast<B*>(&p)) {
//         (void)b;
//         std::cout << "Identified by reference: ";
//         printStr("B", "P");
//     } else if (C* c = dynamic_cast<C*>(&p)) {
//         (void)c;
//         std::cout << "Identified by reference: ";
//         printStr("C", "P");
//     } else {
//         printStr("Error: Could not identify the reference", "R");
//     }
// }

void identify(Base& p) {
    std::cout << "Identified by reference: ";

    try {
        (void)dynamic_cast<A&>(p);
        printStr("A", "P");
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        printStr("B", "P");
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        printStr("C", "P");
    } catch (...) {}
}

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "----------------------" << std::endl;
        Base *base;
    
        base = generate();
        identify(base);
        identify(*base);

        delete base;
    }
    
    return 0;
}