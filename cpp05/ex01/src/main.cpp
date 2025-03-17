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

#include "../inc/Bureaucrat.hpp"
#include "../inc/Utils.hpp"

void    illegalForms(std::string name, int gradeSign, int gradeExec) {
    try {
        std::cout << name << " with sign grade: " << gradeSign 
                          << " and exec grade: " << gradeExec << std::endl;
        Form f2 = Form(name, gradeSign, gradeExec);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl << std::endl;
    }
}

int main(void)
{

    illegalForms("SignTooHighForm", 151, 30);
    illegalForms("ExecTooHighForm", 30, 151);  
    illegalForms("SignTooLowForm", -420, 42);  
    illegalForms("ExecTooLowForm", 69, 0);  ;

    printStr("----------------------------------------------------------", "Y");
    printStr("------------------- Next Form's Turn ---------------------", "Y");
    printStr("----------------------------------------------------------", "Y");    
    std::cout << std::endl;

    try {
        Bureaucrat b2("🔥 Prince Zuko");
        std::cout << b2 << std::endl;

        Form f1("📜 Fire Nation Form", 10, 5);
        std::cout << f1 << std::endl;

        b2.signForm(f1);
        std::cout << std::endl;

        b2.incrementGrade(148);
        std::cout << b2 << std::endl;

        b2.signForm(f1);
        std::cout << std::endl;
    } 
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl << std::endl;
    }

    return 0;
}
