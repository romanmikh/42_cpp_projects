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
    if (ac < 2)
    {
        printStr("Usage: ./PmergeMe $(shuf -i 1-15 | tr '\\n' ' ')", RED);
        return 1;
    }

    std::string input;
    for (int i = 1; i < ac; ++i) {
        input += av[i];
        if (i + 1 < ac)
            input += " ";
    }

    PmergeMe algo;
    std::cout << CYAN << "*** Ford-Johnson Merge-Insertion Sort *** " << RESET << std::endl << std::endl;
    std::cout << YELLOW << "Unsorted: " << RESET << input << std::endl;
    
    
    /* vector approach */
    clock_t startVec = clock();
    algo.sortVec(input);
    double elapsedVecTime = static_cast<double>(clock() - startVec) / CLOCKS_PER_SEC;


    /* list approach */
    clock_t startList = clock();
    algo.sortList(input);
    double elapsedListTime = static_cast<double>(clock() - startList) / CLOCKS_PER_SEC;


    std::cout << std::endl << "Elapsed time using vectors: " << GREEN << elapsedVecTime * 1000 << RESET << " ms" << std::endl;
    std::cout << "Elapsed time using lists:   " << RED << elapsedListTime * 1000 << RESET << " ms" << std::endl;


    return 0;
}
