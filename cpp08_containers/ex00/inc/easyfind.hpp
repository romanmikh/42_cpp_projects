/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Utils.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

/*
 C++ contains 3 types of arrays
 1. C-style arrays:     int arr[5] = {1, 2, 3, 4, 5};
 2. std::array:         std::array<int, 5> arr = {1, 2, 3, 4, 5};
 3. std::vector:        std::vector<int> arr = {1, 2, 3, 4, 5};
*/

/* templates */
template <typename T>
static int easyfind(const T& container, const int val)
{
    typename T::const_iterator it;
    
    it = std::find(container.begin(), container.end(), val);
    if (it == container.end())
        throw std::out_of_range("No such occurence in container! 💀");
    return *it;
}