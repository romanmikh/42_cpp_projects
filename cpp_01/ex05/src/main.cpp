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

#include "../inc/Harl.hpp"

int main(void) {
    Harl harl;
    std::string input;
    std::string validLevels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    while (true) {
        std::cout << "\nEnter level: ";
        if (!std::getline(std::cin, input)) {
			std::cout << "\nEOF detected. Exiting program." << std::endl;
			std::exit(EXIT_SUCCESS);
		}
        // if (std::cin.eof()) {
        //     std::freopen("/dev/tty", "r", stdin);
        //     std::cin.clear();
        //     std::cin.ignore(10000, '\n');
        //     continue;
        }
        if (input.empty()) // Ignore empty input
            continue;
        if (input == "exit")
            break;

        bool valid = false;
        for (int i = 0; i < 4; i++) {
            if (input == validLevels[i]) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            std::cout << "You silly billy, give Harl something he can work with" << std::endl;
            continue;
        }
        harl.complain(input);
    }

    return 0;
}
