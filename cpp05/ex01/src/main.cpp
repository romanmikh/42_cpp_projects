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

int main(void)
{
    try {
        Bureaucrat b2("🔥 Prince Zuko");
        std::cout << b2 << std::endl;

        Form f1("📜 Fire Nation Form", 10, 5);
        std::cout << f1 << std::endl;

        b2.signForm(f1);
        std::cout << std::endl;

        b2.incrementGrade(148);
        std::cout << std::endl;

        b2.signForm(f1);
        std::cout << std::endl;
    } 
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl << std::endl;
    }

    return 0;
}
