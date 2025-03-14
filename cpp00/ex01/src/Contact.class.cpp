/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:43:01 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 16:02:54 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "Contact.class.hpp"

Contact::Contact( void )
{
	// std::cout << "Contact constructor called" << std::endl;
	return ;

}

Contact::~Contact( void )
{
	// std::cout << "Contact destructor called" << std::endl;
	return ;
}

std::string Contact::getName(void) const
{
	return this->_name;
}

void Contact::setName(std::string name)
{
	this->_name = name;
	return ;
}

std::string Contact::getSurname(void) const
{
	return this->_surname;
}

void Contact::setSurname(std::string surname)
{
	this->_surname = surname;
	return ;
}

std::string Contact::getNickname(void) const
{
	return this->_nickname;
}

void Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
	return ;
}

std::string Contact::getMobileNumber(void) const
{
	return this->_mobile_number;
}

void Contact::setMobileNumber(std::string mobile_number)
{
	this->_mobile_number = mobile_number;
	return ;
}

std::string Contact::getSecret(void) const
{
	return this->_secret;
}

void Contact::setSecret(std::string secret)
{
	this->_secret = secret;
	return ;
}