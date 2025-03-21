/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <cmath>

class WrongAnimal {
    
    public:

        /* construcotrs & destructors */
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &other);
        virtual ~WrongAnimal(void);  // virtual destructor in base class

        /* operator overloads */
        WrongAnimal & operator = (const WrongAnimal &other);
        
        /* accessors */
        std::string     getType(void) const;
        void            setType(std::string type);

        /* member functions */
        void    makeSound(void) const;  // virtual would enable polymorphism
        
    protected:

        std::string     _type;
};
