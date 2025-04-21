/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Utils.hpp"

/* non-member functions & operators */

class RPN {
    
    protected:

    private:

    public:

        /* construcotrs & destructors */
        RPN(void);
        RPN(const RPN &);
        ~RPN(void);

        /* operator overloads */
        RPN & operator = (const RPN &);
        
        /* accessors */

        /* member functions */
        void        calculate(const std::string &);

        /* static values */

        /* nested classes */

};
