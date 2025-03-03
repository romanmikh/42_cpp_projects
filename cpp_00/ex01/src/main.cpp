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
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int main(void) {

	PhoneBook book;
	std::string action;

	book.setFlag(1);
	std::cout << "> Hello! What would you like to do?" << std::endl;
	while (book.getFlag()) {
		std::cout << "> ADD, SEARCH or EXIT?" << std::endl;
		std::cin >> action;
		if (action == "EXIT")
			break;
		book.setAction(action);
		book.processAction(book);
	}
	return (0);
}
