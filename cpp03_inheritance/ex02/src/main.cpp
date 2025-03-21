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
#include "../inc/FragTrap.hpp"
#include "../inc/Utils.hpp"

int main(void) {
    std::string fragTrapName = "\033[34mSonic\033[0m";
    std::string clapTrapName = "\033[33mTails\033[0m";

    FragTrap fragTrap(fragTrapName);
    ClapTrap clapTrap(clapTrapName);

    fragTrap.printStats();
    clapTrap.printStats();

    std::cout << "\n🔥 The battle begins! 🔥\n" << std::endl;

    printStr(clapTrapName + " sees he is outmatched and heals!");
    clapTrap.beRepaired(200);
    std::cout << std::endl;

    clapTrap.attack(fragTrapName);
    fragTrap.takeDamage(clapTrap.getAttackDmg());
    std::cout << std::endl;

    fragTrap.attack(clapTrapName);
    clapTrap.takeDamage(fragTrap.getAttackDmg());

    std::cout << "\n🔥🔥🔥 The fight intensifies! 🔥🔥🔥\n" << std::endl;

    for (int i = 0; i < 2; i++) {
        clapTrap.attack(fragTrapName);
        fragTrap.takeDamage(clapTrap.getAttackDmg());
        std::cout << std::endl;

        fragTrap.attack(clapTrapName);
        clapTrap.takeDamage(fragTrap.getAttackDmg());
        std::cout << std::endl;
    }

    std::cout << "\n💀 Both fighters are exhausted... 💀\n" << std::endl;

    fragTrap.beRepaired(30);
    clapTrap.beRepaired(30);

    std::cout << "\n✨ They realize fighting is pointless... ✨\n" << std::endl;

    fragTrap.highFivesGuys();
    clapTrap.printStats();
    fragTrap.printStats();

    std::cout << "\n🙌 Friendship prevails! 🙌\n" << std::endl;

    return 0;
}