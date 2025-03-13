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
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ~ClapTrap(void);

    /* operator overloads */
    ClapTrap & operator = (const ClapTrap &other);
    
    /* accessors */
    std::string         getName(void) const;
    unsigned int        getHitPts(void) const;
    unsigned int        getEnergyPts(void) const;
    unsigned int        getAttackDmg(void) const;

    void                setName(std::string value);
    void                setHitPts(unsigned int value);
    void                setEnergyPts(unsigned int value);
    void                setAttackDmg(unsigned int value);

    void                decrementEnergyPts(int amount);
    void                incrementHitPts(int amount);
    void                decrementHitPts(int amount);

    /* member functions */
    void                attack(std::string const & target);
    void                takeDamage(unsigned int amount);
    void                beRepaired(unsigned int amount);
    void                printStats(void) const;

protected:

    std::string         _name;
    unsigned int        _hitPts;
    unsigned int        _energyPts;
    unsigned int        _attackDmg;

};

// non-member functions


#endif