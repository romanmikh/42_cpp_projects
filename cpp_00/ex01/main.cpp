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

int main() {

	PhoneBook book;
	Contact contact;

	std::cout << "Enter a first name:" << std::endl;
	std::cin >> contact.name;
	std::cout << "Enter a surname:" << std::endl;
	std::cin >> contact.surname;
	std::cout << "Enter a nickname:" << std::endl;
	std::cin >> contact.nickname;
	std::cout << "Enter a mobile number ;):" << std::endl;
	std::cin >> contact.mobile_number;
	std::cout << "Enter a secret:" << std::endl;
	std::cin >> contact.secret;
	
	std::cout << "contact.name: " << contact.name << std::endl;

	contact.foo();
	book.add_contact(contact);
	std::cout << "New PhoneBook contact: " << book.contact[0].name << std::endl;

	return (0);
}
