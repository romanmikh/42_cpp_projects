/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>
#include <iostream>
#include <cmath>

class ClapTrap {

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
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator = (const ClapTrap &other);
    ~ClapTrap(void);


    // accessors

    // operators

private:
    std::string         _name;

};

// non-member functions
std::ostream &operator << (std::ostream &out, ClapTrap const &ClapTrap);

#endif