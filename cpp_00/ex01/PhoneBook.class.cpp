/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:42:42 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:29:15 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook( void )
{
	std::cout << "Phonebook constructor called" << std::endl;
	return ;

}

PhoneBook::~PhoneBook( void )
{
	std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}

void	PhoneBook::add_contact(Contact contact)
{
	std::cout << "Adding contact" << std::endl;
	this->contacts[0] = contact;

	return ;
}
