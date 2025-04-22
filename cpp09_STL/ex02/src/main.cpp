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
        printStr("Usage: ./PmergeMe \"$(shuf -i 1-20 | tr '\\n' ' ')\"", RED);
        return 1;
    }

    PmergeMe algo;
    std::cout << YELLOW << "Unsorted: " << RESET << av[1] << std::endl;
    
    
    /* vector approach */
    clock_t startVec = clock();
    algo.sortVec(av[1]);
    double elapsedVecTime = static_cast<double>(clock() - startVec) / CLOCKS_PER_SEC;


    /* list approach */
    clock_t startList = clock();
    algo.sortList(av[1]);
    double elapsedListTime = static_cast<double>(clock() - startList) / CLOCKS_PER_SEC;


    std::cout << "Elapsed time using vectors: " << elapsedVecTime * 1000 << " ms" << std::endl;
    std::cout << "Elapsed time using lists:   " << elapsedListTime * 1000 << " ms" << std::endl;


    return 0;
}
