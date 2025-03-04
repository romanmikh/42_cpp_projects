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
	std::cout << "Everyone in the crowd is now a zombie..." << std::endl << std::endl;

	Zombie *horde = zombieHorde(4, "Chad");

	std::cout << std::endl << "Address of horde: 		" << horde << std::endl;
	std::cout << "Address of first zombie: 	" << &horde[0] << std::endl;

	std::cout << std::endl << "They all call themselves Chad and grow six packs..." << std::endl << std::endl;
	
	for (int i = 0; i < 4; i++)
		horde[i].announce();
	
	std::cout << std::endl << "They all start drinking protein shakes..." << std::endl << std::endl;

	freeHorde(horde);

	return (0);
}
