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

#include "../inc/ScavTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/Utils.hpp"

int main(void) {
    std::string name;
    std::string command;
    std::string target;
    unsigned int amount;

    std::cout << "Enter your ScavTrap name: ";
    std::getline(std::cin, name);
    handleCtrlD();    

    ScavTrap scav(name);

    while (true) {
        scav.printStats();
        std::cout << "Choose an action [attack, damage, repair, exit]: ";
        std::getline(std::cin, command);
        handleCtrlD();

        if (command == "attack") {
            std::cout << "Enter target: ";
            std::getline(std::cin, name);
            handleCtrlD();
            scav.attack(name);
        }
        else if (command == "damage") {
            amount = getUnsignedInt("Enter damage amount: ");
            scav.takeDamage(amount);
        }
        else if (command == "repair") {
            amount = getUnsignedInt("Enter repair amount: ");
            scav.beRepaired(amount);
        }
        else if (command == "exit")
            break;
        else
            printStr("Unknown command! Use: attack, damage, repair, or exit.", "P");
    }

    return 0;
}