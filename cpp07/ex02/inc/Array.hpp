/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Utils.hpp"

/*
 - this exercise wants to teach us about template classes & exceptions
*/
template <typename A>
class Array
{
    private:
        A*          _array;
        unsigned    _size;

    public:
        Array(void) : _array(NULL), _size(0) {}
        Array(unsigned size) : _array(new A[size]), _size(size) {}
        Array(const Array& other) : _array(NULL), _size(0) { *this = other; }
        ~Array(void) { delete[] _array; }

        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] _array;
                _size = other._size;
                _array = new A[_size];
                for (unsigned i = 0; i < _size; i++)
                    _array[i] = other._array[i];
            }
            return *this;
        }

        A& operator[](unsigned index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }

        unsigned size(void) const { return _size; }
};
