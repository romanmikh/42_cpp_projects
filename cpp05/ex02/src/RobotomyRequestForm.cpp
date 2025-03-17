/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/RobotomyRequestForm.hpp"

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
RobotomyRequestForm::RobotomyRequestForm(void)
                    : AForm("RobotomyRequestForm", 72, 45), 
                      _target("🤖 Wall-e") {
    printStr("RobotomyRequestForm default created! :D", "Y");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
                    : AForm("RobotomyRequestForm", 72, 45), 
                      _target(target) {
    printStr("RobotomyRequestForm created using a target! :D", "Y");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other) 
                     : AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), 
                      _target(other._target) {  
    printStr(this->getName() + " copied (deep copy unnecessary)! :D", "Y");
    *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
    printStr("RobotomyRequestForm destroyed! D:", "Y");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm & other) {
    printStr("RobotomyRequestForm assigned (deep is unnecessary)! :D", "Y");
    this->setSigned(other.isSigned());
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
const char* RobotomyRequestForm::GradeTooHighException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "RobotomyRequestForm's grade is too high! (< 1) 💀" + std::string(RESET);
    return msg.c_str();
}

const char* RobotomyRequestForm::GradeTooLowException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "RobotomyRequestForm's grade is too low! (> 150) 💀" + std::string(RESET);
    return msg.c_str();
}

const char* RobotomyRequestForm::FormUnsignedException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "RobotomyRequestForm is unsigned! 💀" + std::string(RESET);
    return msg.c_str();
}

void        RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getExecGrade()) {
        throw RobotomyRequestForm::GradeTooLowException();
    } else if (!this->isSigned()) {
        throw RobotomyRequestForm::FormUnsignedException();
    } else {
        srand(time(NULL));
        int random = rand() % 2;
        if (random == 0) {
            std::cout << GREEN << this->_target 
                    << " has been robotomized successfully! ✅ (50/50)" 
                                                        << RESET << std::endl;
        } else {
            std::cout << RED << this->_target << " robotomy failed! ❌ (50/50)" 
                                                        << RESET << std::endl;
        }
    }
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
