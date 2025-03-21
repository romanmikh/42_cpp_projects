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
#include "../inc/iter.hpp"

/*
  - need <int> to use template because 
  - compiler cannot deduce the type automatically
*/
int main(void)
{
    const size_t len = 5;

    printStr("--------------------- Increment Ints ---------------------", "G");
    int arri[len] = {1, 2, 3, 4, 5};

    ::printArray<int>(arri, len);
    ::iter(arri, len, increment<int>);
    ::printArray<int>(arri, len);

    printStr("------------------- Increment Doubles --------------------", "G");
    double arrd[len] = {1.0, 2.0, 3.0, 4.0, 5.0};

    ::printArray<double>(arrd, len);
    ::iter(arrd, len, increment<double>);
    ::printArray<double>(arrd, len);

    printStr("-------------------- Increment Floats --------------------", "G");
    float arrf[len] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};

    ::printArray<float>(arrf, len);
    ::iter(arrf, len, increment<float>);
    ::printArray<float>(arrf, len);

    printStr("-------------------- Increment Chars ---------------------", "G");
    char arrc[len] = {'a', 'b', 'c', 'd', 'e'};

    ::printArray<char>(arrc, len);
    ::iter(arrc, len, increment<char>);
    ::printArray<char>(arrc, len);

    printStr("-------------------- ToUpper Strings ---------------------", "G");
    std::string arrs[len] = {"abc", "def", "ghi", "jkl", "mno"};

    ::printArray<std::string>(arrs, len);
    ::iter(arrs, len, toUpper<std::string>);
    ::printArray<std::string>(arrs, len);

    return 0;
}


// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };
// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }
// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }
// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];
//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );
//   return 0;
// }