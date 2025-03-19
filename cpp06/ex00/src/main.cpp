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

#include "../inc/Utils.hpp"
#include "../inc/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printStr("Usage: ./output 42", "R");
        return 1;
    }
    try
    {
        ScalarConverter::convert(av[1]);
    }
    catch (std::exception &e)
    {
        printStr(e.what(), "R");
    }

    return 0;
}
