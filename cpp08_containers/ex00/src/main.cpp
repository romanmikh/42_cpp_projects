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

#include "../inc/easyfind.hpp"
#include "../inc/Utils.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

int main(void)
{
    // method 1 in C++98
    std::vector<int> vec;
    for (int i = 0; i < 8; i++)
        vec.push_back(i*i);
    
    // method 2 in C++98
    int arrInts[] = {1, 4, 9, 99};
    std::vector<int> values(arrInts, arrInts + sizeof(arrInts) / sizeof(int));

    for (size_t i = 0; i < values.size(); i++)
    {
        std::cout << PURPLE << "Looking for " << values[i] << RESET << std::endl;
        try {
            int ans = easyfind(vec, values[i]);
            std::cout << "Found " << ans << std::endl;
        } catch (std::exception& e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }

    return 0;
}
