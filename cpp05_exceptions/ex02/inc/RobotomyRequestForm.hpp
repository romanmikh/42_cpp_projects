/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                                           :+:      :+:    :+:   */
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

class RobotomyRequestForm : public AForm{
    
    public:

        /* construcotrs & destructors */
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        ~RobotomyRequestForm(void);

        /* operator overloads */
        RobotomyRequestForm & operator = (const RobotomyRequestForm &other);
        
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