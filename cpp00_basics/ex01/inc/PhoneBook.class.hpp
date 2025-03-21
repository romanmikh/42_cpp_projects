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

	// member variables
	static const int max = 8;

	PhoneBook(void);
	~PhoneBook(void);

	// adding contacts
	void		processAction(PhoneBook &book);
	void 		addContact(void);
	int			isPhonebookFull(void) const;
	void 		replaceFirstContact();
	Contact 	populateContact(Contact &contact);
	void 		incrementNbInst(void);
	void		decrementNbInst(void);

	// searching contacts
	void 		searchContactCheck(void);
	void		searchContact(int i);
	void		printBook(void) const;
	std::string checkInput(std::string input) const;

	// getters and setters
	std::string	getAction(void) const;
	void		setAction(std::string action);
	int			getFlag(void) const;
	void		setFlag(int flag);
	static int	getNbInst(void);

	// handlers
	void		handleCtrlD(void);

private:

	Contact			_book[max];
	int				_flag;
	std::string		_action;
	static int		_nbInst;

};

#endif
