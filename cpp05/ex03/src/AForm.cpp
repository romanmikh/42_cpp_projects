/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/AForm.hpp"

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
AForm::AForm(void) 
                    : _name("MarriageAForm"), 
                      _signed(false), 
                      _gradeSign(100), 
                      _gradeExec(100) {
    printStr("AForm default created! :D", "Y");
}

AForm::AForm(const std::string& name) 
                    : _name(name), 
                      _signed(false), 
                      _gradeSign(100), 
                      _gradeExec(100) {
    printStr(name + " created using a name! :D", "Y");
}

AForm::AForm(const std::string& name, const int gradeSign, const int gradeExec) 
                    : _name(name), 
                      _signed(false), 
                      _gradeSign(gradeSign), 
                      _gradeExec(gradeExec) {
    printStr(name + " created using a name & both grades! :D", "Y");
    if (gradeSign < Bureaucrat::maxGrade || gradeExec < Bureaucrat::maxGrade)
        throw AForm::GradeTooHighException();
    if (gradeSign > Bureaucrat::minGrade || gradeExec > Bureaucrat::minGrade)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & other) 
                    : _name(other._name), 
                      _signed(false), 
                      _gradeSign(other._gradeSign), 
                      _gradeExec(other._gradeExec) {  
    printStr(_name + " copied (deep copy unnecessary)! :D", "Y");
    *this = other;
}

AForm::~AForm(void){
    printStr("AForm destroyed! D:", "Y");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
AForm & AForm::operator = (const AForm & other) {
    printStr("AForm assigned (deep is unnecessary)! :D", "G");
    this->_signed = other._signed;
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
const std::string AForm::getName(void) const {
    return this-> _name;
}

int AForm::getSignGrade(void) const {
    return this->_gradeSign;
}

int AForm::getExecGrade(void) const {
    return this->_gradeExec;
}

bool AForm::isSigned(void) const {
    return this->_signed;
}

void AForm::setSigned(bool signedStatus) {
    this->_signed = signedStatus;
}

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
const char* AForm::GradeTooHighException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "AForm's grade is too high! (< 1) 💀" + std::string(RESET);
    return msg.c_str();
}

const char* AForm::GradeTooLowException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "AForm's grade is too low! (> 150) 💀" + std::string(RESET);
    return msg.c_str();
}

const char* AForm::FormUnsignedException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "AForm is unsigned! 💀" + std::string(RESET);
    return msg.c_str();
}

void        AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeSign) {
        // printStr(this->_name + " cannot be signed! ❌", "R");
        throw AForm::GradeTooLowException();
    } else {
        // printStr(this->_name + " signed! 📝", "G");
        this->_signed = true;
    }
}

// void        AForm::execute(Bureaucrat const & executor) const {
//     if (!this->isSigned()) {
//         printStr(this->_name + " cannot be executed (unsigned)! ❌", "R");
//         throw AForm::FormUnsignedException();
//     } else if (executor.getGrade() > this->_gradeExec) {
//         printStr(this->_name + " cannot be executed (b too low)! ❌", "R");
//         throw AForm::GradeTooLowException();
//     }
//      else {
//         printStr(this->_name + " executed! 📝", "G");
//     }
// }

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
std::ostream & operator << (std::ostream & out, const AForm& f) {
    out << f.getName() << "'s signGrade: " << f.getSignGrade() 
                       << ", execGrade: " << f.getExecGrade() << std::endl;
    return out;
}