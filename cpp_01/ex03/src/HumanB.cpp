/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"
#include "../inc/Weapon.hpp"

// ************************************************************************** //
//                      Constructors & Desctructors                           //
// ************************************************************************** //
HumanB::HumanB(std::string const name) : _name(name), _weapon(NULL)
{
    std::cout << this->_name << " is ready to duel!" << std::endl;
    return ;
}

HumanB::~HumanB(void)
{
    std::cout << this->_name << " died :(" << std::endl;
    return ;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
void        HumanB::setWeapon(Weapon &weapon)
{
    if (weapon.getType().empty())
    {
            std::cout << "Decides to use the ol' fisty cuffs" << std::endl;
    }
    else
    {
            std::cout << "He now has a weapon!" << std::endl;
    }
    if (weapon.getType().empty())
		this->_weapon = NULL;
	else
		this->_weapon = &weapon;
    return ;
}


// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
void        HumanB::attack(void) const
{
    std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
    return ;
}
