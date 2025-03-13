/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FlagTRAP_H
# define FlagTRAP_H

#include "../inc/ClapTrap.hpp"

class FlagTrap : public ClapTrap {

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
    FlagTrap(std::string name);
    FlagTrap(const FlagTrap &other);
    ~FlagTrap(void);

    /* operator overloads */
    FlagTrap & operator = (const FlagTrap &other);

    /* member functions */
    void    attack(std::string const & target);
    void    highFivesGuys(void);
    void    printStats(void) const;

private:
	FlagTrap(void);
};

/* non-member functions */

#endif