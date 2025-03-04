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

#include <iostream>
#include "../inc/Zombie.hpp"

int main(void) {

	std::cout << "Zombie nuke hits the beatles concert..." << std::endl << std::endl;

	Zombie *zombie1 = newZombie("John");
	Zombie *zombie2 = newZombie("Paul");
	Zombie *zombie3 = newZombie("George");
	Zombie *zombie4 = newZombie("Ringo");

	std::cout << std::endl << "Two random dudes also convert, vocalise & get cured..." << std::endl << std::endl;

	randomChump("Bill");
	randomChump("Frank");

	std::cout << std::endl << "Zombie beatles respond..." << std::endl << std::endl;

	zombie1->announce();
	zombie2->announce();
	zombie3->announce();
	zombie4->announce();

	std::cout << std::endl << "Zombie apocalypse averted!" << std::endl << std::endl;

	delete zombie1;
	delete zombie2;
	delete zombie3;
	delete zombie4;

	return (0);
}
