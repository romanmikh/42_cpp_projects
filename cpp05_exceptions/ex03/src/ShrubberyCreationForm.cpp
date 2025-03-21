/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

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
ShrubberyCreationForm::ShrubberyCreationForm(void)
                    : AForm("ShrubberyCreationForm", 145, 137), 
                      _target("Home ") {
    printStr("ShrubberyCreationForm default created! :D", "Y");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
                    : AForm("ShrubberyCreationForm", 145, 137), 
                      _target(target) {
    printStr("ShrubberyCreationForm created using a target! :D", "Y");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) 
                     : AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), 
                      _target(other._target) {  
    printStr(this->getName() + " copied (deep copy unnecessary)! :D", "Y");
    *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
    printStr("ShrubberyCreationForm destroyed! D:", "Y");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm & other) {
    printStr("ShrubberyCreationForm assigned (deep is unnecessary)! :D", "Y");
    this->setSigned(other.isSigned());
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
const char* ShrubberyCreationForm::GradeTooHighException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "ShrubberyCreationForm's grade is too high! (< 1) 💀" + std::string(RESET);
    return msg.c_str();
}

const char* ShrubberyCreationForm::GradeTooLowException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "ShrubberyCreationForm's grade is too low! (> 150) 💀" + std::string(RESET);
    return msg.c_str();
}

const char* ShrubberyCreationForm::FormUnsignedException::what(void) const throw() {
    static std::string msg = std::string(RED) 
            + "ShrubberyCreationForm is unsigned! 💀" + std::string(RESET);
    return msg.c_str();
}

void        ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getExecGrade()) {
        throw ShrubberyCreationForm::GradeTooLowException();
    } else if (!this->isSigned()) {
        throw ShrubberyCreationForm::FormUnsignedException();
    } else {
        std::ofstream file((this->_target + "_shrubbery").c_str());
        if (file.is_open()) {
            file << "      /\\      \n"
                    "     /\\*\\     \n"
                    "    /\\O\\*\\    \n"
                    "   /*/\\/\\/\\   \n"
                    "  /\\O\\/\\*\\/\\  \n"
                    " /\\*\\/\\*\\/\\/\\ \n"
                    "/\\O\\/\\/*/\\/O/\\ \n"
                    "      ||      \n"
                    "      ||      \n"
                    "      ||      \n";
            file.close();
        }
    }
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
