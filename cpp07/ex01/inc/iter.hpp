/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
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

template <typename A, typename F>
static void iter(A* arr, size_t len, F func)
{
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

template <typename A>
static void printArray(A const* arr, size_t len)
{
    std::cout << "[";
    for (size_t i = 0; i < len; i++)
        std::cout << arr[i] << (i < len - 1 ? ", " : "");
    std::cout << "]" << std::endl;
}

template <typename A>
void increment(A& n) { n++; }

template <typename A>
void toUpper(std::string& str) {
    for (std::string::iterator it = str.begin(); it != str.end(); it++)
        *it = std::toupper(*it);
}
