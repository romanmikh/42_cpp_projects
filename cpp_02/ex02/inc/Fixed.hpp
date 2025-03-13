/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <string>
#include <iostream>
#include <cmath>

class Fixed {

public:
    // ********************************************************************** //  
    //                      Orthodox Canonical Class Form                     //  
    // ---------------------------------------------------------------------- //
    // 1. Default constructor                                                 //  
    //    - initialises object with defaut values. Allocates memory.          //  
    //                                                                        //
    // 2. Copy constructor                                                    //  
    //    - allows 'MyClass a = b;'                                           //  
    //    - initialises copy of existing object. Allocates separate memory.   //  
    //    - const prevents modification of original object.                   //  
    //    - & passing parent by ref (by value would invoke copy constructor)  //  
    //    - & ensures full object is copied.                                  //  
    //                                                                        //
    // 3. Copy assignment operator overload                                   //  
    //    - allows chain assignment 'a = b = c;'. Allocates separate memory.  //  
    //    a) takes parent (other) by reference (const prevents modification)  //  
    //    b) frees old memory                                                 //  
    //    c) creates deep copy (allocates new memory)                         //  
    //                                                                        //
    // 4. Destructor                                                          //  
    //    - releases resources when object goes out of scope, prevents leaks. //  
    // ********************************************************************** //
    Fixed(void);
    Fixed(const int val);
    Fixed(const float val);
    Fixed(const Fixed & other);
    ~Fixed(void);

    // operator overloads
    Fixed & operator = (const Fixed & other); // modifies *this so no const at end

    // specific to ex02
    bool operator > (const Fixed & other) const;
    bool operator < (const Fixed & other) const;
    bool operator >= (const Fixed & other) const;
    bool operator <= (const Fixed & other) const;
    bool operator == (const Fixed & other) const;
    bool operator != (const Fixed & other) const;

    Fixed operator + (const Fixed & other) const;   // no & bc don't modify *this
    Fixed operator - (const Fixed & other) const;
    Fixed operator * (const Fixed & other) const;
    Fixed operator / (const Fixed & other) const;

    Fixed & operator ++ (void); // prefix
    Fixed & operator -- (void); // so decrements *this and returns ref to new obj
    Fixed operator ++ (int);    // postfix
    Fixed operator -- (int);    // so decrements *this and returns copy of old obj

    static Fixed & min(Fixed & a, Fixed & b);
    static Fixed & max(Fixed & a, Fixed & b);

    static const Fixed & min(const Fixed & a, const Fixed & b);
    static const Fixed & max(const Fixed & a, const Fixed & b);

    // accessors
    int                 getRawBits(void) const;
    void                setRawBits(int const raw);

    // utility functions
    float               toFloat(void) const;
    int                 toInt(void) const;

private:

    int                 _val;
    static const int    _fracBits = 8;

};

std::ostream & operator << (std::ostream & out, Fixed const & fixed);

#endif