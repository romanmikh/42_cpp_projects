/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact {

public:

	Contact(void);
	~Contact(void);

	void 		setName(std::string name);
	void 		setSurname(std::string surname);
	void 		setNickname(std::string nickname);
	void 		setMobileNumber(std::string mobile_number);
	void 		setSecret(std::string secret);

	std::string getName(void) const;
	std::string getSurname(void) const;
	std::string getNickname(void) const;
	std::string getMobileNumber(void) const;
	std::string getSecret(void) const;

private:

	std::string _name;
	std::string _surname;
	std::string _nickname;
	std::string _mobile_number;
	std::string _secret;

};

#endif
