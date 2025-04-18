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
    printStr("BitcoinExchange created! :D", GREEN);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) {
    printStr("BitcoinExchange copied! :D", GREEN);
    *this = other;
}

BitcoinExchange::~BitcoinExchange(void){
    printStr("BitcoinExchange destroyed! D:\n", GREEN);
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
int 	BitcoinExchange::isFileEmpty(std::ifstream &file) const {
	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
		return 1;
	file.seekg(0, std::ios::beg);
	return 0;
}

void 	BitcoinExchange::printFile(std::string fileName) const
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
}

void    BitcoinExchange::readData(const char * filename) const {
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

void    BitcoinExchange::processFile(std::string fileName) const {
	std::ifstream file(fileName.c_str());
	if (!file) {
		std::cerr << "> Error: cannot open " << fileName 
					<< " for reading." << std::endl;
		return ;
	}

	std::string line;
	while (std::getline(file, line)) {
		if (line.empty() || line[0] == 'd') {
			continue;
		}
		std::vector<std::string> split = splitByStr(line, " | ");
		if (split.size() != 2) {
			std::cerr << RED << "> Error: invalid line format: " << line << RESET << std::endl;
			continue;
		}
		if (!isValidDate(split[0])) {
			std::cerr << RED << "> Error: invalid date format: " << split[0] << RESET << std::endl;
			continue;
		}
		int valInt;
		float valFloat;
		if (parseInt(split[1], valInt)) {
			if (valInt < 0) {
				std::cerr << RED << "> Error: negative value: " << line << RESET << std::endl;
				continue;
			}
		} else if (parseFloat(split[1], valFloat)) {
			if (valFloat < 0 || valFloat > 1000) {
				std::cerr << RED << "> Error: negative value: " << line << RESET << std::endl;
				continue;
			}
		} else {
			std::cerr << RED << "> Error: invalid value format: " << line << RESET << std::endl;
			continue;
		}



		// Process each line of the file
		std::cout << "Processing line: " << line << std::endl;
	}
	file.close();
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
