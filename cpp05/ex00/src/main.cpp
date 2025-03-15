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

void    illegalAritocrats(std::string name, int grade) {
    try {
        printStr(name + " is trying to become a bureaucrat...");
        Bureaucrat b3 = Bureaucrat(name, grade);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl << std::endl;
    }
}

int main(void)
{
    illegalAritocrats("🟢 Shrek", 99999999);
    illegalAritocrats("🫏 Donkey", 151);  
    illegalAritocrats("🐉 Dragon", 0);  
    illegalAritocrats("👸 Fiona", -100);  ;

    printStr("------------------------------------------------------", "Y");
    printStr("-------------- Next Bureaucrat's Turn ----------------", "Y");
    printStr("------------------------------------------------------", "Y");    
    std::cout << std::endl;

    try {
        Bureaucrat b2("🔥 Prince Zuko");
        std::cout << b2 << std::endl;

        for (int i = 0; i < 3; i++) {
            b2.incrementGrade(1);
            std::cout << b2 << std::endl;
        }
        for (int i = 0; i < 4; i++) {
            b2.decrementGrade(1);
            std::cout << b2 << std::endl;
        }
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl << std::endl;
    }

    printStr("------------------------------------------------------", "Y");
    printStr("-------------- Next Bureaucrat's Turn ----------------", "Y");
    printStr("------------------------------------------------------", "Y");    
    std::cout << std::endl;

    try {
        Bureaucrat b1("👑 Lord Farquaad", 1);
        std::cout << b1 << std::endl;

        for (int i = 0; i < 3; i++) {
            b1.decrementGrade(1);
            std::cout << b1 << std::endl;
        }
        for (int i = 0; i < 4; i++) {
            b1.incrementGrade(1);
            std::cout << b1 << std::endl;
        }
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    printStr("------------------------------------------------------", "Y");
    printStr("-------------- Next Bureaucrat's Turn ----------------", "Y");
    printStr("------------------------------------------------------", "Y");    
    std::cout << std::endl;

    try {
        Bureaucrat b4("👢 Puss in Boots", 50);
        Bureaucrat b5 = b4;
        std::cout << b4 << std::endl;
        std::cout << b5 << std::endl;

        for (int i = 0; i < 3; i++) {
            b5.decrementGrade(15);
            std::cout << b5 << std::endl;
        }
        for (int i = 0; i < 4; i++) {
            b5.incrementGrade(20);
            std::cout << b5 << std::endl;
        }
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
