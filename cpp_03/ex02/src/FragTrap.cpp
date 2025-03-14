/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/FragTrap.hpp"

// ************************************************************************** //
//             Orthodox Canonical Constructors & Desctructors                 //
// ************************************************************************** //
FragTrap::FragTrap(void) : ClapTrap() {
    setHitPts(100);
    setEnergyPts(100);
    setAttackDmg(30);
    printStr("FragTrap Tails created! :D", "B");
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    printStr("FragTrap " + name + " created! :D", "B");
    setHitPts(100);
    setEnergyPts(100);
    setAttackDmg(30);
}

FragTrap::FragTrap(const FragTrap & other) : ClapTrap() {
    printStr("FragTrap " + other.getName() + " copied! :D", "B");
    *this = other;
}

FragTrap::~FragTrap(void){
    printStr("FragTrap " + this->getName() + " destroyed! D:", "B");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
FragTrap & FragTrap::operator = (const FragTrap & other) {
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
void    FragTrap::highFivesGuys(void) {
    printStr("Frag " + this->getName() + " high fives everyone! 🙌", "G");
}

void                FragTrap::printStats(void) const {
    printStr("------------------------ FragStats ------------------------", "B");
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
