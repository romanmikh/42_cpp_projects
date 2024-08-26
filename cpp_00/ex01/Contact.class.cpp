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
#include "Contact.class.hpp"

Contact::Contact( void )
{
	std::cout << "Contact constructor called" << std::endl;
	return ;

}

Contact::~Contact( void )
{
	std::cout << "Contact destructor called" << std::endl;
	return ;
}

void	Contact::foo( void )
{
	std::cout << "foo has been called by Contact class" << std::endl;
	return ;
}
