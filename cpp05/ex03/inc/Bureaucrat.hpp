/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
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

class AForm;  // forward delcaration to avoid circular dependency

class Bureaucrat {
    
    public:

        /* construcotrs & destructors */
        Bureaucrat(void);
        Bureaucrat(const std::string name);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat(void);

        /* operator overloads */
        Bureaucrat & operator = (const Bureaucrat &other);
        
        /* accessors */
        const std::string   getName(void) const;
        int                 getGrade(void) const;
        void                setGrade(int grade);

        /* member functions */
        void                incrementGrade(int d);
        void                decrementGrade(int d);
        void                signForm(AForm& form);
        void                executeForm(AForm const & form);

        /* static values */
        static const int    maxGrade = 1;
        static const int    minGrade = 150;


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
        int                 _grade;

};

/* non-member functions & operators */
std::ostream &	operator<<(std::ostream & os, Bureaucrat const & obj);