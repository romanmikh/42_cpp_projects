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
#include <string>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "Phonebook constructor called" << std::endl;
	max = 3;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}

void	PhoneBook::processAction(PhoneBook &book)
{
	int req = -1;
	// std::cout << "Processing action" << std::endl;
	
	if (book.action == "ADD")
	{
		// std::cout << "Adding contact" << std::endl;
		book.addContact();
	}
	else if (book.action == "SEARCH")
	{

		printBook();
		std::cout << "> Which one would you like to expand?" << std::endl;
		std::cin >> req;

		
		while (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number beterrn 0 and " << max -1 << ": ";
            std::cin.clear();  // Clear error state
            std::cin.ignore(10000, '\n');  // Discard invalid input
			std::cin >> req;
        }
		if (req >= 0 && req < getNbInst())
		{
			book.searchContact(req);
		}
		else
			std::cout << "> Invalid request" << std::endl;
		
	}
	else if (book.action == "EXIT")
	{
		std::cout << "> Exiting" << std::endl;
		book.flag = 0;
	}
	else
	{
		std::cout << "> Invalid action" << std::endl;
	}
	return ;
}

Contact PhoneBook::populateContact(Contact &contact)
{
	std::cout << "> Enter first name: ";
	std::cin >> contact.name;
	std::cout << "> Enter last name: ";
	std::cin >> contact.surname;
	std::cout << "> Enter nickname: ";
	std::cin >> contact.nickname;
	std::cout << "> Enter mobile number: ";
	std::cin >> contact.mobile_number;
	std::cout << "> Enter secret: ";
	std::cin >> contact.secret;

	return contact;
}

std::string PhoneBook::checkInput(std::string input)
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

void	PhoneBook::printBook(void)
{
	int	i = 0;
	std::cout << "|------------------------------------------------------|" << std::endl;
	std::cout << "|Name      |Surname   |Nickname  |Mobile    |Secret    |" << std::endl;
	std::cout << "|------------------------------------------------------|" << std::endl;
	while (i <= max-1 && !this->book[i].name.empty())
	{
		std::cout << "|" << checkInput(this->book[i].name) 
                  << "|" << checkInput(this->book[i].surname)
                  << "|" << checkInput(this->book[i].nickname) 
                  << "|" << checkInput(this->book[i].mobile_number)
                  << "|" << checkInput(this->book[i].secret) << "|"
                  << std::endl;
		i++;
	}
	std::cout << "|------------------------------------------------------|" << std::endl;
}

void	PhoneBook::searchContact(int i)
{
	std::cout << "Name:		" << this->book[i].name << std::endl
			  << "Surname:	" << this->book[i].surname << std::endl
			  << "Nickname:	" << this->book[i].nickname << std::endl
			  << "Mobile:		" << this->book[i].mobile_number << std::endl
			  << "Secret:		" << this->book[i].secret << std::endl;
	return ;
}

int	PhoneBook::isPhonebookFull(void)
{
	// std::cout << "Checking if phonebook is full" << std::endl;

	if (PhoneBook::getNbInst() >= max)
	{
		std::cout << "> Phonebook is full" << std::endl;
		return 1;
	}
	return 0;
}

void	PhoneBook::addContact(void)
{
	int i = getNbInst();
	
	// std::cout << "Adding contact" << std::endl;
	if (isPhonebookFull())
		replaceFirstContact();
	else
	{
		populateContact(book[i]);
	}	
	incrementNbInst();
	return ;
}

void PhoneBook::replaceFirstContact()
{
	// std::cout << "Replacing first contact" << std::endl;
	for (int i = max - 2; i >= 0; i--)
	{
		// std::cout << "i: " << i << std::endl;
		this->book[i + 1] = this->book[i];
	}
	populateContact(book[0]);
	return ;
}

void PhoneBook::incrementNbInst(void)
{
	PhoneBook::_nbInst += 1;
	// std::cout << "Instances open: " << _nbInst << std::endl;
}

void PhoneBook::decrementNbInst(void)
{
	PhoneBook::_nbInst -= 1;
	// std::cout << "Instances open: " << _nbInst << std::endl;
}

int PhoneBook::getNbInst(void)
{
    return PhoneBook::_nbInst;
}

int PhoneBook::_nbInst = 0;  // initialize static=non-member attribute
