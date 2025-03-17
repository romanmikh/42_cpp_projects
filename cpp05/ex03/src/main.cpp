/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main(void)
{

    printStr("---------------------------------------------------------------");
    printStr("------------------------ Construction -------------------------");
    printStr("---------------------------------------------------------------");
    std::cout << std::endl; 

    Intern intern;

    AForm *sf = NULL, *rf = NULL, *pf = NULL;

    try {
        sf = intern.makeForm("ShrubberyCreationForm", "whatever");
        rf = intern.makeForm("RobotomyRequestForm", "whatever");
        pf = intern.makeForm("PresidentialPardonForm", "whatever");

        std::cout << std::endl;    
        std::cout << *sf;
        std::cout << *rf;
        std::cout << *pf << std::endl;

        printStr("---------------------------------------------------------------");
        printStr("------------------------- Destruction -------------------------");
        printStr("---------------------------------------------------------------");
        std::cout << std::endl; 
        
        delete sf;
        delete rf;
        delete pf;
    } catch (Intern::InvalidFormName &e) {
        std::cout << e.what() << std::endl;
    }    

    printStr("---------------------------------------------------------------");
    printStr("-------------------------- Fail Case --------------------------");
    printStr("---------------------------------------------------------------");
    std::cout << std::endl; 
    
    try {
        AForm *wtf = intern.makeForm("skibbidy I don't exist", "whatever"); 
        (void)wtf;
        std::cout << std::endl;    

    } catch (Intern::InvalidFormName &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
