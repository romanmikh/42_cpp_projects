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

#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "Phonebook constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}

// ************************************************************************** //
//                             Redirecting Action                             //
// ************************************************************************** //
void	PhoneBook::processAction(PhoneBook &book)
{	
	if (getAction() == "ADD")
		book.addContact();
	else if (getAction() == "SEARCH")
		searchContactCheck();
	else
		std::cout << "> Invalid action" << std::endl;
	return ;
}

void	PhoneBook::handleCtrlD(void)
{
	if (std::cin.eof())
		{
			std::cout << "\nCTRL+D detected. Exiting program..." << std::endl;
			std::exit(0);
		}
}

// ************************************************************************** //
//                               Adding Contact                               //
// ************************************************************************** //
void	PhoneBook::addContact(void)
{
	int i = getNbInst();
	
	if (isPhonebookFull())
		replaceFirstContact();
	else
		populateContact(_book[i]);
	incrementNbInst();
	return ;
}

int	PhoneBook::isPhonebookFull(void) const
{
	return PhoneBook::getNbInst() >= max;
}

void PhoneBook::replaceFirstContact()
{
	for (int i = max - 2; i >= 0; i--)
		this->_book[i + 1] = this->_book[i];
	populateContact(_book[0]);
	decrementNbInst();
	return ;
}

Contact PhoneBook::populateContact(Contact &contact)
{
	std::string	name;
	std::string	surname;
	std::string	nickname;
	std::string	mobile_number;
	std::string	secret;

	std::cout << "> Enter first name: ";
	std::cin >> name;
	handleCtrlD();
	contact.setName(name);

	std::cout << "> Enter last name: ";
	std::cin >> surname;
	handleCtrlD();
	contact.setSurname(surname);

	std::cout << "> Enter nickname: ";
	std::cin >> nickname;
	handleCtrlD();
	contact.setNickname(nickname);

	std::cout << "> Enter mobile number: ";
	std::cin >> mobile_number;
	handleCtrlD();
	contact.setMobileNumber(mobile_number);

	std::cout << "> Enter secret: ";
	std::cin >> secret;
	handleCtrlD();
	contact.setSecret(secret);

	return contact;
}

// ************************************************************************** //
//                             Searching Contact                              //
// ************************************************************************** //
void PhoneBook::searchContactCheck(void)
{
	int req = -1;
	
	printBook();
	if (getNbInst() > 0)
	{
		std::cout << "> Which one would you like to expand? Between 0 and " \
			<< _nbInst - 1  << std::endl;
		std::cin >> req;

		handleCtrlD();
		while (std::cin.fail()) {
			std::cout << "> Invalid input. Enter a number between 0 and " \
				<< _nbInst - 1 << ": ";
			std::cin.clear();  // Clear error state
			std::cin.ignore(10000, '\n');  // Discard invalid input
			std::cin >> req;
		}
		if (req >= 0 && req < getNbInst())
			searchContact(req);
		else
			std::cout << "> Invalid input. Next time enter between 0 and " \
				<< _nbInst - 1 << std::endl;
	}
	return ;
}

void	PhoneBook::printBook(void) const
{
	int	i = 0;
	std::cout << "|------------------------------------------------------|" << std::endl;
	std::cout << "|Name      |Surname   |Nickname  |Mobile    |Secret    |" << std::endl;
	std::cout << "|------------------------------------------------------|" << std::endl;
	while (i <= max-1 && !this->_book[i].getName().empty())
	{

		Contact contact = this->_book[i];

		std::cout << "|" << checkInput(contact.getName()) 
                  << "|" << checkInput(contact.getSurname())
                  << "|" << checkInput(contact.getNickname()) 
                  << "|" << checkInput(contact.getMobileNumber())
                  << "|" << checkInput(contact.getSecret()) << "|"
                  << std::endl;
		i++;
	}
	std::cout << "|------------------------------------------------------|" << std::endl;
	return ;
}

std::string PhoneBook::checkInput(std::string input) const
{
	if (input.length() > 10)
	{
		input.resize(9);
		input.append(".");
	}
	else if (input.length() < 10)
	{
		while (input.length() < 10)
			input.insert(0, " ");
	}
	return input;
}

void	PhoneBook::searchContact(int i)
{
	Contact contact = this->_book[i];

	std::cout << "Name:		" << contact.getName() << std::endl
			  << "Surname:	" << contact.getSurname() << std::endl
			  << "Nickname:	" << contact.getNickname() << std::endl
			  << "Mobile:		" << contact.getMobileNumber() << std::endl
			  << "Secret:		" << contact.getSecret() << std::endl;
	return ;
}

// ************************************************************************** //
//                                  Accessors                                 //
// ************************************************************************** //
std::string PhoneBook::getAction(void) const
{
	return this->_action;
}

void PhoneBook::setAction(std::string action)
{
	this->_action = action;
	return ;
}

int PhoneBook::getFlag(void) const
{
	return this->_flag;
}

void PhoneBook::setFlag(int flag)
{
	this->_flag = flag;
	return ;
}

int PhoneBook::getNbInst(void)
{
    return PhoneBook::_nbInst;
}

void PhoneBook::incrementNbInst(void)
{
	PhoneBook::_nbInst += 1;
}

void PhoneBook::decrementNbInst(void)
{
	PhoneBook::_nbInst -= 1;
}

int PhoneBook::_nbInst = 0;  // initialize non-member attribute
