/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Utils.hpp"

/* templates*/
/*
    - could have used struct Utils {} and delcare template <typename T>
    - once only, instead of above each functin
*/

template <typename T>
static void         swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

/* 
    1st const is for the return type, output immutable
    2nd & 3rd mean a & b are immutable within scope
    static -> callable by whatever::min(), without instantiation
*/
template <typename T>
static const T      min(T const a, T const b) {
    return (a < b) ? a : b;
}

template <typename T>
static const T      max(T const a, T const b) {
    return (a > b) ? a : b;
}

template <typename T>
static void	        printValues(T const& a, T const& b) {
    std::cout << "a: " << a << ", b: " << b << std::endl;
};