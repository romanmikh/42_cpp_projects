/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/ScavTrap.hpp"

// ************************************************************************** //
//             Orthodox Canonical Constructors & Desctructors                 //
// ************************************************************************** //
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    printStr("ScavTrap " + name + " created! :D", "C");
    setHitPts(100);
    setEnergyPts(50);
    setAttackDmg(20);
}

ScavTrap::~ScavTrap(void){
    printStr("ScavTrap " + this->getName() + " destroyed! D:", "C");
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
void    ScavTrap::attack(std::string const &target) {
    if (this->getHitPts() < 1) {
        printStr("Scav" + this->getName() + " is already dead! 💀", "R");
        return ;
    }
    if (this->getEnergyPts() < 1) {
        printStr("Scav" + this->getName() + " is out of energy! ⛽", "R");
        return ;
    }
    std::cout << "Scav" << this->getName() << " karate chops " << target 
                << " in the face, causing " 
                << this->getAttackDmg() << " points of damage! 🤯" << std::endl;
    this->decrementEnergyPts(1);
}

void    ScavTrap::guardGate(void) {
    printStr("Scav" + this->getName() + " enters Gate keeper mode! 🚧", "G");
}

void                ScavTrap::printStats(void) const {
    printStr("------------------------ ScavStats ------------------------", "Y");
    std::cout << "  Name:             " << this->getName() << std::endl; 
    std::cout << "  Hit Points:       " << this->getHitPts() << std::endl;
    std::cout << "  Energy Points:    " << this->getEnergyPts() << std::endl;
    std::cout << "  Attack Damage:    " << this->getAttackDmg() << std::endl;
    printStr("-----------------------------------------------------------", "Y");
}


// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
