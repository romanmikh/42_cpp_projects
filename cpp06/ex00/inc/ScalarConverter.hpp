/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Utils.hpp"

class ScalarConverter {
    
    public:

        /* construcotrs & destructors */
        ~ScalarConverter(void);

        /* operator overloads */
        ScalarConverter & operator = (const ScalarConverter &other);
        
        /* accessors */

        /* member functions */
        static void        convert(const std::string& str);
        static bool _handlePseudoLiterals(const std::string str, float vFloat, 
                                                            double vDouble);

        /* nested classes */
        class	ImpossibleException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
        
    protected:

    private:
        /* constructors & destructors */
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &other);

};

/* non-member functions & operators */