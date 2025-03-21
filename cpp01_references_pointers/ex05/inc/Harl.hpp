/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_H
# define HARL_CLASS_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstdio>

class Harl {

public:

    Harl(void);
    ~Harl(void);

    void complain( std::string level );

    std::string level;

private:

    void _debug( void );
    void _info( void );
    void _warning( void );
    void _error( void );

};

#endif