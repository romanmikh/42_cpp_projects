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
ClapTrap::ClapTrap(void) 
                : _name("Sonic"), _hitPts(10),  _energyPts(10), _attackDmg(0) {
    printStr("ClapTrap Sonic created! :D", "Y");
}

ClapTrap::ClapTrap(std::string name) 
                    : _name(name), _hitPts(10),  _energyPts(10), _attackDmg(0) {
    printStr("ClapTrap " + name + " created! :D", "Y");
}

ClapTrap::ClapTrap(const ClapTrap & other) {
    printStr("ClapTrap " + other.getName() + " copied! :D", "Y");
    *this = other;
}

ClapTrap::~ClapTrap(void){
    printStr("ClapTrap " + this->_name + " destroyed! D:", "Y");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
ClapTrap & ClapTrap::operator = (const ClapTrap & other) {
    if (this != &other) {
        this->_name = other.getName();
        this->_hitPts = other.getHitPts();
        this->_energyPts = other.getEnergyPts();
        this->_attackDmg = other.getAttackDmg();
    }
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
std::string ClapTrap::getName(void) const {
    return this->_name;
}

unsigned int ClapTrap::getHitPts(void) const {
    return this->_hitPts;
}

unsigned int ClapTrap::getEnergyPts(void) const {
    return this->_energyPts;
}

unsigned int ClapTrap::getAttackDmg(void) const {
    return this->_attackDmg;
}

void        ClapTrap::setName(std::string name) {
    this->_name = name;
}

void        ClapTrap::setHitPts(unsigned int value) {
    this->_hitPts = value;
}

void        ClapTrap::setEnergyPts(unsigned int value) {
    this->_energyPts = value;
}

void        ClapTrap::setAttackDmg(unsigned int value) {
    this->_attackDmg = value;
}

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
