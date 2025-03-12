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
    std::string         getName(void) const;
    int                 getHitPts(void) const;
    int                 getEnergyPts(void) const;
    int                 getAttackDmg(void) const;

    void                setName(std::string name);
    void                setHitPts(int hitPts);
    void                setEnergyPts(int energyPts);
    void                setAttackDmg(int attackDmg);

    void                incrementEnergyPts(int amount);
    void                decrementEnergyPts(int amount);
    void                incrementHitPts(int amount);
    void                decrementHitPts(int amount);
    void                incrementAttackDmg(int amount);
    void                decrementAttackDmg(int amount);

    // member functions
    void                attack(std::string const & target);
    void                takeDamage(unsigned int amount);
    void                beRepaired(unsigned int amount);
    void                printStats(void) const;

private:
    std::string         _name;
    unsigned int        _hitPts;
    unsigned int        _energyPts;
    unsigned int        _attackDmg;

};

// non-member functions


#endif