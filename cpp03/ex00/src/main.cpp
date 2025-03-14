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

#include "../inc/ClapTrap.hpp"
#include "../inc/Utils.hpp"

int main(void) {
    std::string name;
    std::string command;
    std::string target;
    unsigned int amount;

    std::cout << "Enter your ClapTrap name: ";
    std::getline(std::cin, name);
    handleCtrlD();    

    ClapTrap clap(name);

    while (true) {
        clap.printStats();
        std::cout << "Choose an action [attack, damage, repair, exit]: ";
        std::getline(std::cin, command);
        handleCtrlD();

        if (command == "attack") {
            std::cout << "Enter target: ";
            std::getline(std::cin, name);
            handleCtrlD();
            clap.attack(name);
        }
        else if (command == "damage") {
            amount = getUnsignedInt("Enter damage amount: ");
            clap.takeDamage(amount);
        }
        else if (command == "repair") {
            amount = getUnsignedInt("Enter repair amount: ");
            clap.beRepaired(amount);
        }
        else if (command == "exit")
            break;
        else
            printStr("Unknown command! Use: attack, damage, repair, or exit.", "P");
    }

    return 0;
}