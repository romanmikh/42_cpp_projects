/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Animal.hpp"

class Dog : public Animal {
    
    public:

        /* construcotrs & destructors */
        Dog(void);
        Dog(const Dog &other);
        ~Dog(void);

        /* operator overloads */
        Dog & operator = (const Dog &other);
        
        /* accessors */

        /* member functions */
        void    makeSound(void) const;

};

/* non-member functions */
