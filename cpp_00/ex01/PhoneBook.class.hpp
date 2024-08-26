/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:29:04 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:21:48 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include <iostream>
#include "Contact.class.hpp"

class PhoneBook {

public:

	std::string contacts[8];
	PhoneBook( void );
	~PhoneBook( void );

	void add_contact(Contact contact);
};

#endif
