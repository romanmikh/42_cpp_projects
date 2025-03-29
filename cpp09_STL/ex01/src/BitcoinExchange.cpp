/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/BitcoinExchange.hpp"

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
BitcoinExchange::BitcoinExchange(void) {
    printStr("BitcoinExchange created! :D", "G");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) {
    printStr("BitcoinExchange copied! :D", "G");
    *this = other;
}

BitcoinExchange::~BitcoinExchange(void){
    printStr("BitcoinExchange destroyed! D:\n", "G");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
BitcoinExchange & BitcoinExchange::operator = (const BitcoinExchange & other) {
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
int 	BitcoinExchange::isFileEmpty(std::ifstream &file) {
	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
		return 1;
	file.seekg(0, std::ios::beg);
	return 0;
}

void 	BitcoinExchange::printFile(std::string fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file) {
		std::cerr << "> Error: cannot open " << fileName 
					<< " for reading." << std::endl;
		return ;
	}

	std::string newLine;
	while (std::getline(file, newLine)) {
		std::cout << newLine << std::endl;
	}
	file.close();
}\

void    BitcoinExchange::readData(const char * filename) {
    std::ifstream file(filename);
    if (!file.is_open())
    {
        printStr("Error: file not found", "R");
        return;
    }
    if (isFileEmpty(file)) {
		std::cerr << "> Error: " << filename << " is empty." << std::endl;
		return ;
	}
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
