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

#include "../inc/Fixed.hpp"
#include "../inc/Utils.hpp"

int main( void )
{

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}

// int main() {
//     Fixed a(5.5f);
//     Fixed b(2);
//     Fixed c(10);
//     Fixed d(5.5f);

//     std::cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;

//     // Test arithmetic operators
//     std::cout << "a + b = " << (a + b) << std::endl;
//     std::cout << "a - b = " << (a - b) << std::endl;
//     std::cout << "a * b = " << (a * b) << std::endl;
//     std::cout << "a / b = " << (a / b) << std::endl;

//     // Test comparison operators
//     std::cout << "a > b ? " << (a > b) << std::endl;
//     std::cout << "a < b ? " << (a < b) << std::endl;
//     std::cout << "a >= d ? " << (a >= d) << std::endl;
//     std::cout << "a <= d ? " << (a <= d) << std::endl;
//     std::cout << "a == d ? " << (a == d) << std::endl;
//     std::cout << "a != d ? " << (a != d) << std::endl;

//     // Test increment and decrement
//     std::cout << "a before ++: " << a << std::endl;
//     std::cout << "++a: " << ++a << std::endl;
//     std::cout << "a after ++: " << a << std::endl;
//     std::cout << "a++: " << a++ << std::endl;
//     std::cout << "a after a++: " << a << std::endl;

//     std::cout << "b before --: " << b << std::endl;
//     std::cout << "--b: " << --b << std::endl;
//     std::cout << "b after --: " << b << std::endl;
//     std::cout << "b--: " << b-- << std::endl;
//     std::cout << "b after b--: " << b << std::endl;

//     // Test min/max
//     std::cout << "min(a, c) = " << Fixed::min(a, c) << std::endl;
//     std::cout << "max(a, c) = " << Fixed::max(a, c) << std::endl;

//     return 0;
// }