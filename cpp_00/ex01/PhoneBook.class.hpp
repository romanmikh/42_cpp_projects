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
#include <string>
#include "Contact.class.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	Contact		book[3];

	int			max;
	int			flag;
	std::string	action;

	void		processAction(PhoneBook &book);
	Contact 	populateContact(Contact &contact);
	void 		addContact(void);
	int			isPhonebookFull(void);
	void		setContact(Contact &contact);
	void 		replaceFirstContact();
	Contact 	getContact(void);
	static int	getNbInst(void);
	void 		incrementNbInst(void);
	void		decrementNbInst(void);
	void		printBook(void);
	void		searchContact(int i);
	std::string checkInput(std::string input);

private:

	static int	_nbInst;

};

#endif
