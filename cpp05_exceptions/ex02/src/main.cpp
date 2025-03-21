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

int main(void)
{

    printStr("-----------------------------------------------------------------------------------------");
    printStr("------------------------------------- Construction --------------------------------------");
    printStr("-----------------------------------------------------------------------------------------");
    std::cout << std::endl; 

    Bureaucrat b2("🔥 Prince Zuko", 150);
    std::cout << b2 << std::endl;

    ShrubberyCreationForm sf1("🏠 Home");
    RobotomyRequestForm rf1("🤖 Wall-e");
    PresidentialPardonForm pf1("👽 ");

    std::cout << std::endl;
    std::cout << sf1;
    std::cout << rf1;
    std::cout << pf1 << std::endl;

    printStr("-----------------------------------------------------------------------------------------");
    printStr("---------------------------- Incrimenting Bureaucrat Level ------------------------------");
    printStr("-----------------------------------------------------------------------------------------"); 
    std::cout << std::endl;

    int increments[] = {0, 6, 9, 85, 10, 30, 8};
    for (int i = 0; i < 7; ++i)
    {
        b2.incrementGrade(increments[i]);
        std::cout << b2 << std::endl;

        b2.signForm(sf1);
        b2.executeForm(sf1);
        b2.signForm(rf1);
        b2.executeForm(rf1);
        b2.signForm(pf1);
        b2.executeForm(pf1);
        std::cout << std::endl;
    }

    printStr("-----------------------------------------------------------------------------------------");
    printStr("----------------------------- Testing = Overload Operator -------------------------------");
    printStr("-----------------------------------------------------------------------------------------"); 
    std::cout << std::endl;

    ShrubberyCreationForm sf2 = sf1;
    RobotomyRequestForm rf2 = rf1;
    PresidentialPardonForm pf2 = pf1;
    
    std::cout << std::endl;
    std::cout << sf2;
    std::cout << rf2;
    std::cout << pf2 << std::endl;

    b2.signForm(sf2);
    b2.executeForm(sf2);
    b2.signForm(rf2);
    b2.executeForm(rf2);
    b2.signForm(pf2);
    b2.executeForm(pf2);
    std::cout << std::endl;

    printStr("-----------------------------------------------------------------------------------------");
    printStr("------------------------------ Testing Copy Constructor ---------------------------------");
    printStr("-----------------------------------------------------------------------------------------"); 
    std::cout << std::endl;

    ShrubberyCreationForm sf3(sf1);
    RobotomyRequestForm rf3(rf1);
    PresidentialPardonForm pf3(pf1);

    std::cout << std::endl;
    std::cout << sf3;
    std::cout << rf3;
    std::cout << pf3 << std::endl;

    b2.signForm(sf3);
    b2.executeForm(sf3);
    b2.signForm(rf3);
    b2.executeForm(rf3);
    b2.signForm(pf3);
    b2.executeForm(pf3);
    std::cout << std::endl;  

    printStr("-----------------------------------------------------------------------------------------");
    printStr("------------------------------------- Destruction ---------------------------------------");
    printStr("-----------------------------------------------------------------------------------------"); 
    std::cout << std::endl;

    return 0;
}
