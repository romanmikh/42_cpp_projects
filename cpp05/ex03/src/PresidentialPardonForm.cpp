/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/PresidentialPardonForm.hpp"

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
PresidentialPardonForm::PresidentialPardonForm(void)
                    : AForm("PresidentialPardonForm", 25, 5), 
                      _target("🤖 Wall-e") {
    printStr("PresidentialPardonForm default created! :D", "Y");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
                    : AForm("PresidentialPardonForm", 25, 5), 
                      _target(target) {
    printStr("PresidentialPardonForm created using a target! :D", "Y");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other) 
                     : AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), 
                      _target(other._target) {  
    printStr(this->getName() + " copied (deep copy unnecessary)! :D", "Y");
    *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(void){
    printStr("PresidentialPardonForm destroyed! D:", "Y");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm & other) {
    printStr("PresidentialPardonForm assigned (deep is unnecessary)! :D", "Y");
    this->setSigned(other.isSigned());
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
const char* PresidentialPardonForm::GradeTooHighException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "PresidentialPardonForm's grade is too high! (< 1) 💀" + std::string(RESET);
    return msg.c_str();
}

const char* PresidentialPardonForm::GradeTooLowException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "PresidentialPardonForm's grade is too low! (> 150) 💀" + std::string(RESET);
    return msg.c_str();
}

const char* PresidentialPardonForm::FormUnsignedException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "PresidentialPardonForm is unsigned! 💀" + std::string(RESET);
    return msg.c_str();
}

void        PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getExecGrade()) {
        throw PresidentialPardonForm::GradeTooLowException();
    } else if (!this->isSigned()) {
        throw PresidentialPardonForm::FormUnsignedException();
    } else
        std::cout << GREEN << this->_target 
        << "has been pardoned by Zaphod Beeblebrox! 🎉" << RESET << std::endl;
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
