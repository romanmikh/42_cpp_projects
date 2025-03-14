/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"

class Cat : public Animal {
    
    public:

        /* construcotrs & destructors */
        Cat(void);
        Cat(const Cat &other);
        ~Cat(void);

        /* operator overloads */
        Cat & operator = (const Cat &other);
        
        /* accessors */
        volatile Brain*      getBrain(void) const;

        /* member functions */
        void        makeSound(void) const;

    protected:

    private:
        Brain*   _brain;
};

/* non-member functions */
