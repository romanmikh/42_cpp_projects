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

#include "../inc/BitcoinExchange.hpp"

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

void    BitcoinExchange::processFile(std::string fileName) const {

	std::ifstream file;
	std::ifstream dataFile;
	if (!isValidFile(fileName.c_str(), file) || !isValidFile("data.csv", dataFile)) {
		return ; 
	}
	
	std::string line;
	while (std::getline(file, line)) {
		if (line.empty() || line[0] == 'd') {
			continue;
		}
		dataFile.clear();               // clear EOF flag
		dataFile.seekg(0, std::ios::beg); // rewind to beginning

		std::vector<std::string> lineSplit = splitByStr(line, " | ");
		if (lineSplit.size() != 2) {
			std::cerr << RED << "> Error: invalid line format: " << line << RESET << std::endl;
			continue;
		}
		if (!isValidDate(lineSplit[0])) {
			std::cerr << RED << "> Error: invalid date format: " << lineSplit[0] << RESET << std::endl;
			continue;
		}
		if (lineSplit[1] == "2147483648") {
			std::cerr << RED << "> Error: value > MAX_INT: " << line << RESET << std::endl;
			continue;
		}
		int valInt;
		float valFloat;
		if (parseInt(lineSplit[1], valInt)) {
			if (valInt < 0) {
				std::cerr << RED << "> Error: negative value: " << line << RESET << std::endl;
				continue;
			}
			valFloat = static_cast<float>(valInt);
		} else if (parseFloat(lineSplit[1], valFloat)) {
			if (valFloat < 0 || valFloat > 1000) {
				std::cerr << RED << "> Error: negative value: " << line << RESET << std::endl;
				continue;
			}
		} else {
			std::cerr << RED << "> Error: invalid value format: " << line << RESET << std::endl;
			continue;
		}

		// Process each line of the file
		float adjVal = -1;
		std::string dataLine, bestLine;
		int bestDate = -1, targetDate = dateToInt(lineSplit[0]);

		while (std::getline(dataFile, dataLine)) {
			std::vector<std::string> dataSplit = split(dataLine, ',');
			if (dataSplit.size() != 2) continue;
			int date = dateToInt(dataSplit[0]);
			if (date <= targetDate && date > bestDate) {
				bestLine = dataLine;
				bestDate = date;
			}
		}

		if (bestDate != -1) {
			std::vector<std::string> dataSplit = split(bestLine, ',');
			adjVal = std::atof(dataSplit[1].c_str()) * valFloat;
			std::cout << lineSplit[0] << " => " << lineSplit[1] << " = " << adjVal << std::endl;
		} else {
			std::cerr << RED << "> No match for " << lineSplit[0] << RESET << std::endl;
		}
	}
	file.close();
	dataFile.close();
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
