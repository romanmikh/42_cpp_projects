/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
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

class Brain {
    
    public:

        /* construcotrs & destructors */
        Brain(void);
        Brain(const Brain &other);
        virtual     ~Brain(void);  // virtual destructor in base class 

        /* operator overloads */
        Brain & operator = (const Brain &other);
        
        /* accessors */
        const std::string&      getIdea(int index) const;
        void                    setIdea(std::string idea, int index);

        /* member functions */
        
    protected:
    
    private:

        std::string     _ideas[100];    // virtual only applies to functions
};

/* non-member functions */