/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Utils.hpp"
#include <stack>

/*
 - std::stack provides LIFO stack to an underlying container
 - e.g. it can be a wrapper for vector<int>
 - pushes and pops to/from top of stack
 ----------------------------------------------------------------
 - we inherit from std::stack and add more functionality
 - two variables in template so we can specify element type and container type
 - 
*/

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        /* member types */
        typedef typename std::stack<T>::container_type::iterator        iterator;
        typedef typename std::stack<T>::container_type::const_iterator  const_iterator;

        /* construcotrs & destructors */
        MutantStack(void) : std::stack<T>() {}
        MutantStack<T>(const MutantStack& other) : std::stack<T>(other) {}
        ~MutantStack<T>(void) {}
        /*
         - don't need <T> after MutantStack bc inside class, would need outside
         - adding anyway to show both versions work inside class
        */ 

        /* operator overloads */
        /*
         - commented code causes infinte recursion (segfault)
         - because it calls itself, using the = operator, which we're defining..
         - whereas ->c calls a member, which doesn't use our = operator
        */
        MutantStack<T>& operator=(const MutantStack& other)
        {
            if (this != &other)
            {
                // *this = other;
                this->c = other.c;
            }
            return *this;
        }

        /* member functions */
        /*
         - c is a protected member of std::stack, holding underlying container
         - by default it's std::deque<T>
         - std::deque<T> is a double-ended queue container (access from front and back)
         - internally implemented as dynamic array, unlike std::vector (contiguous)
        */ 
        MutantStack<T>::iterator    begin(void)
        {
            return this->c.begin();
        }

        MutantStack<T>::iterator    end(void)
        {
            return this->c.end();
        }

};





/* non-member functions & operators */