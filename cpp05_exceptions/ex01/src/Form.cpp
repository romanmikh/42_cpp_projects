/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/Form.hpp"

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
Form::Form(void) 
                    : _name("MarriageForm"), 
                      _signed(false), 
                      _gradeSign(100), 
                      _gradeExec(100) {
    printStr("Form default created! :D", "Y");
}

Form::Form(const std::string& name) 
                    : _name(name), 
                      _signed(false), 
                      _gradeSign(100), 
                      _gradeExec(100) {
    printStr(name + " created using a name! :D", "Y");
}

Form::Form(const std::string& name, const int gradeSign, const int gradeExec) 
                    : _name(name), 
                      _signed(false), 
                      _gradeSign(gradeSign), 
                      _gradeExec(gradeExec) {
    printStr(name + " created using a name & both grades! :D", "Y");
    if (gradeSign < Bureaucrat::maxGrade || gradeExec < Bureaucrat::maxGrade)
        throw Form::GradeTooHighException();
    if (gradeSign > Bureaucrat::minGrade || gradeExec > Bureaucrat::minGrade)
        throw Form::GradeTooLowException();
}

Form::Form(const Form & other) 
                    : _name(other._name), 
                      _signed(false), 
                      _gradeSign(other._gradeSign), 
                      _gradeExec(other._gradeExec) {  
    printStr(_name + " copied (deep copy unnecessary)! :D", "Y");
    *this = other;
}

Form::~Form(void){
    printStr("Form destroyed! D:", "Y");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
Form & Form::operator = (const Form & other) {
    printStr("Form assigned (deep is unnecessary)! :D", "G");
    this->_signed = other._signed;
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
const std::string Form::getName(void) const {
    return this-> _name;
}

int Form::getSignGrade(void) const {
    return this->_gradeSign;
}

int Form::getExecGrade(void) const {
    return this->_gradeExec;
}

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
const char* Form::GradeTooHighException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "Form's grade is too high! (< 1) 💀" + std::string(RESET);
    return msg.c_str();
}

const char* Form::GradeTooLowException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "Form's grade is too low! (> 150) 💀" + std::string(RESET);
    return msg.c_str();
}

void        Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeSign) {
        // printStr(this->_name + " cannot be signed! ❌", "R");
        throw Form::GradeTooLowException();
    } else {
        // printStr(this->_name + " signed! 📝", "G");
        this->_signed = true;
    }
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
std::ostream & operator << (std::ostream & out, const Form& f) {
    out << f.getName() << "'s signGrade: " << f.getSignGrade() 
                       << ", execGrade: " << f.getExecGrade() << std::endl;
    return out;
}