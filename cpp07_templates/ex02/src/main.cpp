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
#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    printStr("-------------------- Default Constructor ---------------------", "G");
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;

    printStr("\n-------------------- Constructor with size ---------------------", "G");
    Array<int> b(5);
    for (unsigned i = 0; i < b.size(); ++i)
        b[i] = i * 10;
    std::cout << "b: ";
    for (unsigned i = 0; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    printStr("\n-------------------- Copy Constructor ---------------------", "G");
    Array<int> c(b);
    c[0] = 999;
    std::cout << "c[0] = " << c[0] << ", b[0] = " << b[0] << " (should be different)" << std::endl;

    printStr("\n-------------------- Assignment Constructor ---------------------", "G");
    Array<int> d;
    d = b;
    d[1] = 888;
    std::cout << "d[1] = " << d[1] << ", b[1] = " << b[1] << " (should be different)" << std::endl;

    printStr("\n-------------------- Bounds Checking ---------------------", "G");
    try {
        std::cout << b[42] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printStr("\n-------------------- Complex Type (strings) ---------------------", "G");
    Array<std::string> e(3);
    e[0] = "Hello";
    e[1] = "world";
    e[2] = "!";
    for (unsigned i = 0; i < e.size(); ++i)
        std::cout << e[i] << " ";
    std::cout << std::endl;

    return 0;
}
