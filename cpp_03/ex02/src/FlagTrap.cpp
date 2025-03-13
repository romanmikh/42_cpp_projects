/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/FlagTrap.hpp"

// ************************************************************************** //
//             Orthodox Canonical Constructors & Desctructors                 //
// ************************************************************************** //
FlagTrap::FlagTrap(void) : ClapTrap() {
    setHitPts(100);
    setEnergyPts(100);
    setAttackDmg(30);
    printStr("FlagTrap Tails created! :D", "B");
}

FlagTrap::FlagTrap(std::string name) : ClapTrap(name) {
    printStr("FlagTrap " + name + " created! :D", "B");
    setHitPts(100);
    setEnergyPts(100);
    setAttackDmg(30);
}

FlagTrap::FlagTrap(const FlagTrap & other) : ClapTrap() {
    printStr("FlagTrap " + other.getName() + " copied! :D", "B");
    *this = other;
}

FlagTrap::~FlagTrap(void){
    printStr("FlagTrap " + this->getName() + " destroyed! D:", "B");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
FlagTrap & FlagTrap::operator = (const FlagTrap & other) {
    if (this != &other) {
        setName(other.getName());
        setHitPts(other.getHitPts());
        setEnergyPts(other.getEnergyPts());
        setAttackDmg(other.getAttackDmg());
    }
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
void    FlagTrap::attack(std::string const &target) {
    if (this->getHitPts() < 1) {
        printStr("Flag " + this->getName() + " is already dead! 💀", "R");
        return ;
    }
    if (this->getEnergyPts() < 1) {
        printStr("Flag " + this->getName() + " is out of energy! ⛽", "R");
        return ;
    }
    std::cout << "Flag " << this->getName() << " karate chops " << target 
                << " in the face, causing " 
                << this->getAttackDmg() << " points of damage! 🤯" << std::endl;
    this->decrementEnergyPts(1);
}

void    FlagTrap::highFivesGuys(void) {
    printStr("Flag " + this->getName() + " high fives everyone! 🙌", "G");
}

void                FlagTrap::printStats(void) const {
    printStr("------------------------ FlagStats ------------------------", "B");
    std::cout << "  Name:             " << this->getName() << std::endl; 
    std::cout << "  Hit Points:       " << this->getHitPts() << std::endl;
    std::cout << "  Energy Points:    " << this->getEnergyPts() << std::endl;
    std::cout << "  Attack Damage:    " << this->getAttackDmg() << std::endl;
    printStr("-----------------------------------------------------------", "B");
}


// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
