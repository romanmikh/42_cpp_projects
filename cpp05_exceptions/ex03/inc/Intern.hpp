/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Utils.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
// #include "../inc/Bureaucrat.hpp"

// class AForm;  // forward delcaration to avoid circular dependency

class Intern {
    
    public:

        /* construcotrs & destructors */
        Intern(void);
        Intern(const Intern &other);
        virtual ~Intern(void);

        /* operator overloads */
        Intern & operator = (const Intern &other);
        
        /* accessors */

        /* member functions */
        AForm * makeForm(const std::string& formName, const std::string& target);

        /* nested classes */
        class InvalidFormName : public std::exception {
			public:
				virtual const char * what(void) const throw();
		};
        
    protected:

    private:

        AForm* _makeShrubberyCreationForm(std::string target);
        AForm* _makeRobotomyRequestForm(std::string target);
        AForm* _makePresidentialPardonForm(std::string target);

};

/* non-member functions & operators */