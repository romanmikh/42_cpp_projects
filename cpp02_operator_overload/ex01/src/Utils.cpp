/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"

void printRM(const std::string &text, const std::string &colour) {
    std::string code;
    
    if (colour == "RESET") {
        code = "\033[0m";
    } else if (colour == "R") {
        code = "\033[31m";
    } else if (colour == "G") {
        code = "\033[32m";
    } else if (colour == "Y") {
        code = "\033[33m";
    } else if (colour == "B") {
        code = "\033[34m";
    } else if (colour == "P") {
        code = "\033[35m";
    } else if (colour == "C") {
        code = "\033[36m";
    } else if (colour == "BR") {
        code = "\033[1;31m";
    } else if (colour == "BG") {
        code = "\033[1;32m";
    } else if (colour == "BY") {
        code = "\033[1;33m";
    } else if (colour == "BB") {
        code = "\033[1;34m";
    } else if (colour == "BP") {
        code = "\033[1;35m";
    } else if (colour == "BC") {
        code = "\033[1;36m";
    } else if (colour == "BGR") {
        code = "\033[41m";
    } else if (colour == "BGG") {
        code = "\033[42m";
    } else if (colour == "BGY") {
        code = "\033[43m";
    } else if (colour == "BGB") {
        code = "\033[44m";
    } else if (colour == "BGP") {
        code = "\033[45m";
    } else if (colour == "BGC") {
        code = "\033[46m";
    } else if (colour == "BGW") {
        code = "\033[47m";
    } else {
        code = "\033[37m";  // Default White if no match
    }
    std::cout << code << text << "\033[0m" << std::endl;
}
