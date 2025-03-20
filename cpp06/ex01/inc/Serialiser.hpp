/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialiser.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Utils.hpp"
#include "../inc/Data.hpp"

class Serialiser {
    
    public:

        /* construcotrs & destructors */

        /* operator overloads */
        
        /* accessors */

        /* member functions */
        static uintptr_t       serialise(Data* ptr);    
        static Data*           deserialise(uintptr_t raw);
        // static so that methods can be called without an instance of the class

        /* nested classes */
         
    protected:

    private:
        /* constructors & destructors */
        Serialiser(void);
        Serialiser(const Serialiser &other);
        Serialiser & operator = (const Serialiser &other);
        ~Serialiser(void);

};

/* non-member functions & operators */