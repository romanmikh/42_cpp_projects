/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

// ************************************************************************** //
//                      Constructors & Desctructors                           //
// ************************************************************************** //
Harl::Harl(void)
{
    std::cout << "Harl was born" << std::endl;
    return ;
}

Harl::~Harl(void)
{
    std::cout << "Harl exploded :(" << std::endl;
    return ;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //

void    Harl::complain( std::string level )
{
    typedef void    (Harl::*f)(void);  // pointer on member function

    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    f           functions[4] = { &Harl::_debug, &Harl::_info, 
                                    &Harl::_warning, &Harl::_error };

    // (harl.*f)();  // calls specific ***instance*** of class function
    // (harl->*f)();  // ***pointer to instance***, not instnace
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return ;
        }
    }
    return ;
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //
void   Harl::_debug( void )
{
    std::cout << "Debugging..." << std::endl;
    return ;
}

void   Harl::_info( void )
{
    std::cout << "Info..." << std::endl;
    return ;
}

void   Harl::_warning( void )
{
    std::cout << "Warning..." << std::endl;
    return ;
}

void   Harl::_error( void )
{
    std::cout << "Error..." << std::endl;
    return ;
}