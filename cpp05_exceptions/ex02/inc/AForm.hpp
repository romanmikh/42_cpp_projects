/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
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

class Bureaucrat;  // forward delcaration to avoid circular dependency

class AForm {
    
    public:

        /* construcotrs & destructors */
        AForm(void);
        AForm(const std::string& name);
        AForm(const std::string& name, const int gradeSign, const int gradeExec);
        AForm(const AForm &other);
        virtual ~AForm(void);

        /* operator overloads */
        AForm & operator = (const AForm &other);
        
        /* accessors */
        const std::string   getName(void) const;
        int                 getSignGrade(void) const;  // const on return
        int                 getExecGrade(void) const;  // has no effect
        bool                isSigned(void) const;

        /* member functions */
        void                beSigned(Bureaucrat& bureaucrat);
        virtual void        execute(Bureaucrat const & executor) const = 0;

        /* nested classes */
        /* 
            - virtual: allows what() to be overridden downstream (polymorphism)
            - const: what() does not modify the object when called
            - what(): function name, part of std::exception
            - const: can be called on const objects
            - throw(): what() does *not* throw exceptions
        */
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

        void            setSigned(bool signedStatus);

    private:

        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExec;

};

/* non-member functions & operators */
std::ostream &	operator << (std::ostream & os, AForm const & obj);