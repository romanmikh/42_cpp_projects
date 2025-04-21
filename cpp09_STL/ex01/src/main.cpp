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

#include "../inc/RPN.hpp"
#include "../inc/Utils.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printStr("Usage: ./RPN \"expression\"", "R");
        return 1;
    }

    RPN calculator;
    calculator.calculate(av[1]);
    return 0;
}
