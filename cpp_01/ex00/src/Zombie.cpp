/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << name << " became a zombie!" << std::endl;
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << this->_getName() << " got cured :D" << std::endl;
    return ;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
std::string Zombie::_getName(void) const
{
    return this->_name;
}

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
void Zombie::announce(void)
{
    std::cout << this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}



