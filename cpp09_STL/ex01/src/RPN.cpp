/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

// ************************************************************************** //
//             Orthodox Canonical Constructors & Desctructors                 //
// ************************************************************************** //
RPN::RPN(void) {
    printStr("RPN created! :D", GREEN);
}

RPN::RPN(const RPN & other) {
    printStr("RPN copied! :D", GREEN);
    *this = other;
}

RPN::~RPN(void){
    printStr("RPN destroyed! D:\n", GREEN);
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
RPN & RPN::operator = (const RPN & other) {
    if (this != &other)
        *this = other;
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
void 	RPN::calculate(const std::string & expression) {
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (std::isdigit(token[0])) {
			stack.push(strToInt(token));
		} else {
			if (stack.size() < 2) {
				printStr("Error: Not enough operands", RED);
				return;
			}
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			switch (token[0]) {
				case '+': stack.push(a + b); break;
				case '-': stack.push(a - b); break;
				case '*': stack.push(a * b); break;
				case '/':
					if (b == 0) {
						printStr("Error: Division by zero", RED);
						return;
					}
					stack.push(a / b);
					break;
				default:
					printStr("Error: Invalid operator", RED);
					return;
			}
		}
	}

	if (stack.size() != 1) {
		printStr("Error: Too many operands", RED);
		return;
	}

	std::cout << "Result: " << stack.top() << std::endl;
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
