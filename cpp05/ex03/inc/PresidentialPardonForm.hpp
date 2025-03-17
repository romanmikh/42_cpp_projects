/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Utils.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

class Bureaucrat;  // forward delcaration to avoid circular dependency

class PresidentialPardonForm : public AForm{
    
    public:

        /* construcotrs & destructors */
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        ~PresidentialPardonForm(void);

        /* operator overloads */
        PresidentialPardonForm & operator = (const PresidentialPardonForm &other);
        
        /* accessors */

        /* member functions */
        void        execute(Bureaucrat const & executor) const;

        /* nested classes */
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what(void) const throw();  // void forbidden
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what(void) const throw();
        };

        class FormUnsignedException : public std::exception {
            public:
                virtual const char* what(void) const throw();
        };
        
    protected:

    private:

        std::string   _target;

};

/* non-member functions & operators */