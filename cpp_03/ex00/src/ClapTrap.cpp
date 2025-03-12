/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/ClapTrap.hpp"

// ************************************************************************** //
//             Orthodox Canonical Constructors & Desctructors                 //
// ************************************************************************** //
ClapTrap::ClapTrap(std::string name) 
                    : _name(name), _hitPts(10),  _energyPts(10), _attackDmg(0) {
    printStr("ClapTrap " + name + " created! :D", "G");
    return ;
}

ClapTrap::~ClapTrap(void){
    printStr("ClapTrap " + this->_name + " destroyed! D:", "R");
    return ;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
void        ClapTrap::decrementEnergyPts(int amount) {
    this->_energyPts -= amount;
}

void        ClapTrap::incrementHitPts(int amount) {
    this->_hitPts += amount;
}

void        ClapTrap::decrementHitPts(int amount) {
    this->_hitPts -= amount;
}

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
void                ClapTrap::attack(std::string const &target) {
    if (this->_hitPts < 1) {
        printStr(this->_name + " is already dead! 💀", "R");
        return ;
    }
    if (this->_energyPts < 1) {
        printStr(this->_name + " is out of energy! ⛽", "R");
        return ;
    }
    std::cout << this->_name << " pokes " << target << " in the eye, causing " 
                << this->_attackDmg << " points of damage! 👉👀" << std::endl;
    decrementEnergyPts(1);
}

void                ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPts < 1) {
        printStr(this->_name + " is already dead! 💀", "R");
        return ;
    }
    if (this->_hitPts < amount)
        amount = this->_hitPts;
    std::cout << this->_name << " takes " << amount 
        << " points of damage!" << std::endl;
    decrementHitPts(amount);
}

void                ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPts < 1) {
        printStr(this->_name + " is already dead! 💀", "R");
        return ;
    }
    if (this->_energyPts < 1) {
        printStr(this->_name + " is out of energy! ⛽", "R");
        return ;
    }
    std::cout << this->_name << " heals " << amount 
        << " points! 💙" << std::endl;
    incrementHitPts(amount);
    decrementEnergyPts(1);
}

void                ClapTrap::printStats(void) const{
    printStr("------------------------ ClapStats ------------------------", "Y");
    std::cout << "  Name:             " << this->_name << std::endl; 
    std::cout << "  Hit Points:       " << this->_hitPts << std::endl;
    std::cout << "  Energy Points:    " << this->_energyPts << std::endl;
    std::cout << "  Attack Damage:    " << this->_attackDmg << std::endl;
    printStr("-----------------------------------------------------------", "Y");
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
