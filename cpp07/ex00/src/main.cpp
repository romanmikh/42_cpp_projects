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
#include "../inc/whatever.hpp"

int main(void)
{

    printStr("------------------------ Testing Ints -------------------------");


    int a = 2;
    int b = 3;

    printStr("Originally:", "P");
    whatever::printValues(a, b);
    printStr("After swapping:", "P");
    whatever::printValues(a, b);

    std::cout << "min: " << whatever::min(a, b) << std::endl;
    std::cout << "max: " << whatever::max(a, b) << std::endl;


    printStr("---------------------- Testing Floats -------------------------");


    float c = 2.0f;
    float d = 3.0f;

    printStr("Originally:", "P");
    whatever::printValues(c, d);
    printStr("After swapping:", "P");
    whatever::swap(c, d);
    whatever::printValues(c, d);
    std::cout << "min: " << whatever::min(c, d) << std::endl;
    std::cout << "max: " << whatever::max(c, d) << std::endl;


    printStr("--------------------- Testing Doubles -------------------------");


    double e = 2.0;
    double f = 3.0;

    printStr("Originally:", "P");
    whatever::printValues(e, f);
    printStr("After swapping:", "P");
    whatever::swap(e, f);
    whatever::printValues(e, f);
    std::cout << "min: " << whatever::min(e, f) << std::endl;
    std::cout << "max: " << whatever::max(e, f) << std::endl;



    printStr("--------------------- Testing Longs ---------------------------");


    long g = 2;
    long h = 3;

    printStr("Originally:", "P");
    whatever::printValues(g, h);
    printStr("After swapping:", "P");
    whatever::swap(g, h);
    whatever::printValues(g, h);
    std::cout << "min: " << whatever::min(g, h) << std::endl;
    std::cout << "max: " << whatever::max(g, h) << std::endl;


    printStr("----------------- Testing Unsigned Ints -----------------------");


    unsigned int i = 2;
    unsigned int j = 3;

    printStr("Originally:", "P");
    whatever::printValues(i, j);
    printStr("After swapping:", "P");
    whatever::swap(i, j);
    whatever::printValues(i, j);
    std::cout << "min: " << whatever::min(i, j) << std::endl;
    std::cout << "max: " << whatever::max(i, j) << std::endl;



    printStr("---------------------- Testing Chars --------------------------");

    
    char k = 'a';
    char l = 'b';

    printStr("Originally:", "P");
    whatever::printValues(k, l);
    printStr("After swapping:", "P");
    whatever::swap(k, l);
    whatever::printValues(k, l);
    std::cout << "min: " << whatever::min(k, l) << std::endl;
    std::cout << "max: " << whatever::max(k, l) << std::endl;


    printStr("--------------------- Testing Strings -------------------------");


    std::string m = "aaa";
    std::string n = "bbb";

    printStr("Originally:", "P");
    whatever::printValues(m, n);
    printStr("After swapping:", "P");
    whatever::swap(m, n);
    whatever::printValues(m, n);
    std::cout << "min: " << whatever::min(m, n) << std::endl;
    std::cout << "max: " << whatever::max(m, n) << std::endl;


    printStr("----------------------- Testing Bools -------------------------");


    bool o = true;
    bool p = false;

    printStr("Originally:", "P");
    whatever::printValues(o, p);
    printStr("After swapping:", "P");
    whatever::swap(o, p);
    whatever::printValues(o, p);
    std::cout << "min: " << whatever::min(o, p) << std::endl;
    std::cout << "max: " << whatever::max(o, p) << std::endl;

    return 0;
}
