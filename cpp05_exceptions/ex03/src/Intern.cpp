/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
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
Intern::Intern(void) {
    printStr("Intern default created! :D", "G");
}

Intern::Intern(const Intern & other) {  
    printStr("Intern copied (deep copy unnecessary)! :D", "G");
    *this = other;
}

Intern::~Intern(void){
    printStr("Intern destroyed! D:", "Y");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
Intern & Intern::operator = (const Intern & other) {
    printStr("Intern assigned (deep is unnecessary)! :D", "G");
    (void)other;
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
// AForm * Intern::makeForm(const std::string& formName, const std::string& target) {
//     if (formName == "ShrubberyCreationForm") {
//         return new ShrubberyCreationForm(target);
//     } else if (formName == "RobotomyRequestForm") {
//         return new RobotomyRequestForm(target);
//     } else if (formName == "PresidentialPardonForm") {
//         return new PresidentialPardonForm(target);
//     } else {
//         printStr("Form not found! 😢", "R");
//         return NULL;
//     }
// }

AForm * Intern::makeForm(const std::string& formName, const std::string& target)
{
    typedef AForm*    (Intern::*f)(std::string);

    std::string forms[3] = { "ShrubberyCreationForm", 
                              "RobotomyRequestForm", 
                              "PresidentialPardonForm"};
    f           formFunctions[3] = { &Intern::_makeShrubberyCreationForm, 
                                     &Intern::_makeRobotomyRequestForm, 
                                     &Intern::_makePresidentialPardonForm
                                };

    // (harl.*f)();  // calls specific ***instance*** of class function
    // (harl->*f)();  // ***pointer to instance***, not instnace
    // we could use (harlInstance.*functions[i])(); instead if we did this:
    // Harl harlInstance = *this;  // Create a local instance
    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            printStr("\nIntern made the " + formName + "!", "G");
            return (this->*formFunctions[i])(target);
        }
    }
    throw Intern::InvalidFormName();
    // return NULL;
}

const char* Intern::InvalidFormName::what(void) const throw() {
    static std::string msg = std::string(RED) + "Form not found! 😢" 
                                                        + std::string(RESET);
    return msg.c_str();
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //
AForm * Intern::_makeShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm * Intern::_makeRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm * Intern::_makePresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}


// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //