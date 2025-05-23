/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
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

class Animal {
    
    public:

        /* construcotrs & destructors */
        Animal(void);
        Animal(const Animal &other);
        virtual     ~Animal(void);  // virtual destructor in base class
        // allows destruction of Animal objects via other classes' destructors

        /* operator overloads */
        Animal & operator = (const Animal &other);
        
        /* accessors */
        std::string     getType(void) const;
        void            setType(std::string type);

        /* member functions */
        virtual void    makeSound(void) const;  // enables polymorphism
        
    protected:

        std::string     _type;
};
