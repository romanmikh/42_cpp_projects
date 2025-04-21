/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include "../inc/Utils.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printStr("Usage: ./PmergeMe \"9 1 0 2 8 3 7 4 6 5\"", "R");
        return 1;
    }

    PmergeMe algo;
    algo.sort(av[1]);
    return 0;
}
