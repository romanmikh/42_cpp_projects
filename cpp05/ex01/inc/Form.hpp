/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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

class Form {
    
    public:

        /* construcotrs & destructors */
        Form(void);
        Form(const std::string& name);
        Form(const std::string& name, const int gradeSign, const int gradeExec);
        Form(const Form &other);
        ~Form(void);

        /* operator overloads */
        Form & operator = (const Form &other);
        
        /* accessors */
        const std::string   getName(void) const;
        int                 getSignGrade() const;  // const on return
        int                 getExecGrade() const;  // has no effect

        /* member functions */
        void                beSigned(Bureaucrat& bureaucrat);

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
                virtual const char* what(void) const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what(void) const throw();
        };
        
    protected:

    private:

        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExec;

};

/* non-member functions & operators */
std::ostream &	operator<<(std::ostream & os, Form const & obj);