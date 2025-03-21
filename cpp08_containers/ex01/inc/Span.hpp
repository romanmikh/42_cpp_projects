/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Utils.hpp"

class Span {
    
    protected:

    private:

        std::vector<int> _container;
        unsigned int     _size;

    public:

        /* construcotrs & destructors */
        Span(void);
        Span(unsigned int size);
        Span(const Span &other);
        ~Span(void);

        /* operator overloads */
        Span & operator = (const Span &other);
        
        /* accessors */

        /* member functions */
        void    addNmbr(int nmbr);
        void    addNmbr(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     shortestSpan(void) const;
        int     longestSpan(void) const;
        int     getNmbr(int index) const;
        int     rands(void);

        /* static values */

        /* nested classes */
        class ContainerFullException : public std::exception {
            public:
                virtual const char* what(void) const throw();
        };

        class ContainerEmptyException : public std::exception {
            public:
                virtual const char* what(void) const throw();
        };
};

/* non-member functions & operators */