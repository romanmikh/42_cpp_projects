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
#include <string>

int main(void) {

	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str; // * -> the address of the string
	std::string& stringREF = str;  // & -> ref=alias, same address in memory (same obj coneptually)

	std::cout << "Address of the string: 			" << &str << std::endl;
	std::cout << "Address of the string using pointer: 	" << stringPTR << std::endl;
	std::cout << "Address of the string using reference:	" << &stringREF << std::endl;

	std::cout << "String using variable: 		" << str << std::endl;
	std::cout << "String using pointer: 		" << *stringPTR << std::endl;
	std::cout << "String using reference: 	" << stringREF << std::endl;

	return (0);
}
