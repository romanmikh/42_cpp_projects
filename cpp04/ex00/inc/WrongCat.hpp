/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    
    public:

        /* construcotrs & destructors */
        WrongCat(void);
        WrongCat(const WrongCat &other);
        ~WrongCat(void);

        /* operator overloads */
        WrongCat & operator = (const WrongCat &other);
        
        /* accessors */

        /* member functions */
        void    makeSound(void) const;

};

/* non-member functions */
