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
    printStr("BitcoinExchange destroyed! D:", GREEN);
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

std::map<std::string, float> BitcoinExchange::loadExchangeRates(const char *filename) const {
	std::ifstream dataFile(filename);
	std::map<std::string, float> rates;
	std::string line;

	if (!dataFile)
		return rates;

	while (std::getline(dataFile, line)) {
		std::size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		std::string date = line.substr(0, pos);
		std::string val = line.substr(pos + 1);
		if (!isValidDate(date))
			continue;
		rates[date] = std::atof(val.c_str());
	}
	dataFile.close();
	return rates;
}

bool BitcoinExchange::parseLine(const std::string &line, std::string &date, std::string &valueStr) const {
	std::size_t pos = line.find(" | ");
	if (pos == std::string::npos)
		return false;
	date = line.substr(0, pos);
	valueStr = line.substr(pos + 3);
	return true;
}

void BitcoinExchange::processEntry(const std::string &date, const std::string &valueStr, const std::map<std::string, float> &rates) const {
	if (!isValidDate(date)) {
		std::cerr << RED << "> Error: invalid date format: " << date << RESET << std::endl;
		return;
	}
	if (valueStr == "2147483648") {
		std::cerr << RED << "> Error: value > MAX_INT: " << valueStr << RESET << std::endl;
		return;
	}

	int valInt;
	float valFloat;
	if (parseInt(valueStr, valInt)) {
		if (valInt < 0) {
			std::cerr << RED << "> Error: negative value: " << valueStr << RESET << std::endl;
			return;
		}
		valFloat = static_cast<float>(valInt);
	} else if (parseFloat(valueStr, valFloat)) {
		if (valFloat < 0 || valFloat > 1000) {
			std::cerr << RED << "> Error: invalid range: " << valueStr << RESET << std::endl;
			return;
		}
	} else {
		std::cerr << RED << "> Error: invalid value format: " << valueStr << RESET << std::endl;
		return;
	}

	std::map<std::string, float>::const_iterator it = rates.lower_bound(date);
	if (it == rates.end() || it->first != date) {
		if (it == rates.begin()) {
			std::cerr << RED << "> No match for " << date << RESET << std::endl;
			return;
		}
		--it;
	}

	float result = valFloat * it->second;
	std::cout << date << " => " << valueStr << " = " << result << std::endl;
}

void BitcoinExchange::processFile(std::string fileName) const {
	std::ifstream file(fileName.c_str());
	if (!file || isFileEmpty(file)) {
		std::cerr << RED << "> Error: cannot open or empty file: " << fileName << RESET << std::endl;
		return;
	}

	std::map<std::string, float> rates = loadExchangeRates("data.csv");
	if (rates.empty()) {
		std::cerr << RED << "> Error: failed to load data.csv" << RESET << std::endl;
		return;
	}

	std::string line, date, valueStr;
	while (std::getline(file, line)) {
		if (line.empty() || line[0] == 'd')
			continue;
		if (!parseLine(line, date, valueStr)) {
			std::cerr << RED << "> Error: invalid line format: " << line << RESET << std::endl;
			continue;
		}
		processEntry(date, valueStr, rates);
	}
	file.close();
}


// void    BitcoinExchange::processFile(std::string fileName) const {

// 	std::ifstream file;
// 	std::ifstream dataFile;
// 	if (!isValidFile(fileName.c_str(), file) || !isValidFile("data.csv", dataFile)) {
// 		return ; 
// 	}
	
// 	std::string line;
// 	while (std::getline(file, line)) {
// 		if (line.empty() || line[0] == 'd') {
// 			continue;
// 		}
// 		dataFile.clear();               // clear EOF flag
// 		dataFile.seekg(0, std::ios::beg); // rewind to beginning

// 		std::vector<std::string> lineSplit = splitByStr(line, " | ");
// 		if (lineSplit.size() != 2) {
// 			std::cerr << RED << "> Error: invalid line format: " << line << RESET << std::endl;
// 			continue;
// 		}
// 		if (!isValidDate(lineSplit[0])) {
// 			std::cerr << RED << "> Error: invalid date format: " << lineSplit[0] << RESET << std::endl;
// 			continue;
// 		}
// 		if (lineSplit[1] == "2147483648") {
// 			std::cerr << RED << "> Error: value > MAX_INT: " << line << RESET << std::endl;
// 			continue;
// 		}
// 		int valInt;
// 		float valFloat;
// 		if (parseInt(lineSplit[1], valInt)) {
// 			if (valInt < 0) {
// 				std::cerr << RED << "> Error: negative value: " << line << RESET << std::endl;
// 				continue;
// 			}
// 			valFloat = static_cast<float>(valInt);
// 		} else if (parseFloat(lineSplit[1], valFloat)) {
// 			if (valFloat < 0 || valFloat > 1000) {
// 				std::cerr << RED << "> Error: negative value: " << line << RESET << std::endl;
// 				continue;
// 			}
// 		} else {
// 			std::cerr << RED << "> Error: invalid value format: " << line << RESET << std::endl;
// 			continue;
// 		}

// 		// Process each line of the file
// 		float adjVal = -1;
// 		std::string dataLine, bestLine;
// 		int bestDate = -1, targetDate = dateToInt(lineSplit[0]);

// 		while (std::getline(dataFile, dataLine)) {
// 			std::vector<std::string> dataSplit = split(dataLine, ',');
// 			if (dataSplit.size() != 2) continue;
// 			int date = dateToInt(dataSplit[0]);
// 			if (date <= targetDate && date > bestDate) {
// 				bestLine = dataLine;
// 				bestDate = date;
// 			}
// 		}

// 		if (bestDate != -1) {
// 			std::vector<std::string> dataSplit = split(bestLine, ',');
// 			adjVal = std::atof(dataSplit[1].c_str()) * valFloat;
// 			std::cout << lineSplit[0] << " => " << lineSplit[1] << " = " << adjVal << std::endl;
// 		} else {
// 			std::cerr << RED << "> No match for " << lineSplit[0] << RESET << std::endl;
// 		}
// 	}
// 	file.close();
// 	dataFile.close();
// }
