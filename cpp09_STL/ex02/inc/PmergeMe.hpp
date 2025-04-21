/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
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

class PmergeMe {
    
    protected:

    private:

    public:

        /* construcotrs & destructors */
        PmergeMe(void);
        PmergeMe(const PmergeMe &);
        ~PmergeMe(void);

        /* operator overloads */
        PmergeMe & operator = (const PmergeMe &);
        
        /* accessors */

        /* member functions */
        void        sort(const std::string &);

        /* static values */

        /* nested classes */

};
