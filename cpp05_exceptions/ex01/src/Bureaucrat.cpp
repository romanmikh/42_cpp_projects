/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/Bureaucrat.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

// ************************************************************************** //
//             Orthodox Canonical Constructors & Desctructors                 //
// ************************************************************************** //
Bureaucrat::Bureaucrat(void) : _name("Vincent"), _grade(minGrade) {
    printStr("Bureaucrat default created! :D", "P");
}

Bureaucrat::Bureaucrat(const std::string name) 
                                : _name(name), _grade(minGrade) {
    printStr("Bureaucrat " + name + " created using a name! :D", "P");
}

Bureaucrat::Bureaucrat(const std::string name, int grade) 
                                : _name(name), _grade(minGrade) {
    if (grade < maxGrade)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > minGrade)
        throw Bureaucrat::GradeTooLowException();
    else 
        this->_grade = grade;
    printStr("Bureaucrat " + name + " created usig a name & a grade! :D", "P");
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) 
                                    : _name(other._name), _grade(other._grade) {  
    *this = other;
    printStr("Bureaucrat copied (deep copy unnecessary)! :D", "P");
}

Bureaucrat::~Bureaucrat(void){
    printStr("Bureaucrat destroyed! D:", "P");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
Bureaucrat & Bureaucrat::operator = (const Bureaucrat & other) {
    this->_grade = other._grade;
    printStr("Bureaucrat assigned (deep is unnecessary)! :D", "G");
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
const std::string Bureaucrat::getName(void) const {
    return this-> _name;
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

void Bureaucrat::setGrade(int grade) {
    if (grade > minGrade) {
        throw GradeTooLowException();
    } else if (grade < maxGrade) {
        throw GradeTooHighException();
    }
    this->_grade = grade;
}

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
    static std::string msg = std::string(RED) + "Grade is too high! (< 1) 💀" 
                                                        + std::string(RESET);
    return msg.c_str();
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
    static std::string msg = std::string(RED) + "Grade is too low! (> 150) 💀" 
                                                        + std::string(RESET);
    return msg.c_str();
}

void        Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << GREEN << this->getName() + " signs " + form.getName() 
                                            + " form! 📝" << RESET << std::endl;
    } catch (const std::exception & e) {
        std::cout << RED << this->getName() + " cannot sign " + form.getName() 
                                            + " form! ❌" << RESET << std::endl;
    }
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //
void    Bureaucrat::incrementGrade(int d) {
    if (this->getGrade() - d < maxGrade) {
        throw GradeTooHighException();   // return is redundant
    }
    std::cout << GREEN << this->getName() + "'s grade incremented by " << d 
                                                << " 🔼" << RESET << std::endl;
    this->setGrade(this->getGrade() - d);
}

void    Bureaucrat::decrementGrade(int d) {
    if (this->getGrade() + d > minGrade) {
        throw GradeTooLowException();
    }
    std::cout << RED << this->getName() + "'s grade decremented by " << d 
                                                << " 🔽" << RESET << std::endl;
    this->setGrade(this->getGrade() + d);
}

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
std::ostream & operator << (std::ostream & out, const Bureaucrat & b) {
    out << b.getName() << ", bureaucrat grade: " << b.getGrade() << std::endl;
    return out;
}