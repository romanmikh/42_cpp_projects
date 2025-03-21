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

    ::printStr("----------------------- Testing Ints ------------------------");


    int a = 2;
    int b = 3;

    ::printStr("Originally:", "P");
    ::printValues(a, b);
    ::printStr("After swapping:", "P");
    ::printValues(a, b);

    std::cout << "min: " << ::min(a, b) << std::endl;
    std::cout << "max: " << ::max(a, b) << std::endl;


    ::printStr("--------------------- Testing Floats ------------------------");


    float c = 2.0f;
    float d = 3.0f;

    ::printStr("Originally:", "P");
    ::printValues(c, d);
    ::printStr("After swapping:", "P");
    ::swap(c, d);
    ::printValues(c, d);
    std::cout << "min: " << ::min(c, d) << std::endl;
    std::cout << "max: " << ::max(c, d) << std::endl;


    ::printStr("-------------------- Testing Doubles ------------------------");


    double e = 2.0;
    double f = 3.0;

    ::printStr("Originally:", "P");
    ::printValues(e, f);
    ::printStr("After swapping:", "P");
    ::swap(e, f);
    ::printValues(e, f);
    std::cout << "min: " << ::min(e, f) << std::endl;
    std::cout << "max: " << ::max(e, f) << std::endl;



    ::printStr("-------------------- Testing Longs --------------------------");


    long g = 2;
    long h = 3;

    ::printStr("Originally:", "P");
    ::printValues(g, h);
    ::printStr("After swapping:", "P");
    ::swap(g, h);
    ::printValues(g, h);
    std::cout << "min: " << ::min(g, h) << std::endl;
    std::cout << "max: " << ::max(g, h) << std::endl;


    ::printStr("---------------- Testing Unsigned Ints ----------------------");


    unsigned int i = 2;
    unsigned int j = 3;

    ::printStr("Originally:", "P");
    ::printValues(i, j);
    ::printStr("After swapping:", "P");
    ::swap(i, j);
    ::printValues(i, j);
    std::cout << "min: " << ::min(i, j) << std::endl;
    std::cout << "max: " << ::max(i, j) << std::endl;



    ::printStr("--------------------- Testing Chars -------------------------");

    
    char k = 'a';
    char l = 'b';

    ::printStr("Originally:", "P");
    ::printValues(k, l);
    ::printStr("After swapping:", "P");
    ::swap(k, l);
    ::printValues(k, l);
    std::cout << "min: " << ::min(k, l) << std::endl;
    std::cout << "max: " << ::max(k, l) << std::endl;


    ::printStr("-------------------- Testing Strings ------------------------");


    std::string m = "aaa";
    std::string n = "bbb";

    ::printStr("Originally:", "P");
    ::printValues(m, n);
    ::printStr("After swapping:", "P");
    ::swap(m, n);
    ::printValues(m, n);
    std::cout << "min: " << ::min(m, n) << std::endl;
    std::cout << "max: " << ::max(m, n) << std::endl;


    ::printStr("---------------------- Testing Bools ------------------------");


    bool o = true;
    bool p = false;

    ::printStr("Originally:", "P");
    ::printValues(o, p);
    ::printStr("After swapping:", "P");
    ::swap(o, p);
    ::printValues(o, p);
    std::cout << "min: " << ::min(o, p) << std::endl;
    std::cout << "max: " << ::max(o, p) << std::endl;

    return 0;
}


// class Awesome
// {
//   public:
//     Awesome(void) : _n(0) {}
//     Awesome( int n ) : _n( n ) {}
//     Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
//     bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
//     bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
//     bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
//     bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
//     bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
//     bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
//     int get_n() const { return _n; }
//   private:
//     int _n;
// };
// std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }
// int main(void)
// {
// 	Awesome a(2), b(4);
//         swap(a, b);
//         std::cout << a << " " << b << std::endl;
//         std::cout << max(a, b) << std::endl;
//         std::cout << min(a, b) << std::endl;
//         return (0);
// }