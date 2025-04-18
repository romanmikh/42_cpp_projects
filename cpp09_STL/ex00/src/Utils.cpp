/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"

// ************************************************************************** //
//                                Conversions                                 //
// ************************************************************************** //
std::string intToString(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

std::string uintToString(unsigned int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

std::string boolToString(bool value) {
    return value ? "true" : "false";
}

std::string sizeToString(size_t value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

unsigned int getUnsignedInt(const std::string& prompt) {
    unsigned int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        handleCtrlD();
        std::cout << "Invalid input. Enter a numeric value: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    handleCtrlD();
    std::cin.ignore(1000, '\n');
    return value;
}

bool parseInt(const std::string& s, int& out) {
    std::istringstream iss(s);
    return (iss >> out) && iss.eof();
}

bool parseFloat(const std::string& s, float& out) {
    std::istringstream iss(s);
    return (iss >> out) && iss.eof();
}

// ************************************************************************** //
//                                 Strings                                    //
// ************************************************************************** //
std::vector<std::string> split(const std::string& str, char delimiter)
{
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string elem;

    while (std::getline(ss, elem, delimiter))
        result.push_back(elem);

    return result;
}

std::vector<std::string> splitByStr(const std::string& str, const std::string& delim) {
    std::vector<std::string> result;
    std::string::size_type start = 0;
    std::string::size_type pos;

    while ((pos = str.find(delim, start)) != std::string::npos) {
        result.push_back(str.substr(start, pos - start));
        start = pos + delim.length();
    }

    result.push_back(str.substr(start));
    return result;
}

bool not_space(char c) {
    return !std::isspace(static_cast<unsigned char>(c));
}

std::string trim(const std::string& s) {
    std::string::const_iterator start = std::find_if(s.begin(), s.end(), not_space);
    std::string::const_iterator end = std::find_if(s.rbegin(), s.rend(), not_space).base();
    return (start < end) ? std::string(start, end) : "";
}

void    printStr(const std::string &text, const std::string &colour) {
   std::cout << colour << text << "\033[0m" << std::endl;
}

// ************************************************************************** //
//                                Validations                                 //
// ************************************************************************** //
bool isInteger(const std::string& s) {
    if (s.empty()) return false;
    std::istringstream iss(s);
    int val;
    char c;
    return (iss >> val) && !(iss >> c);
}

bool isFloat(const std::string& s) {
    if (s.empty()) return false;
    std::istringstream iss(s);
    float val;
    char c;
    return (iss >> val) && !(iss >> c);
}

bool isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0)
        return false;

    static const int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    return day <= daysInMonth[month - 1];
}

// ************************************************************************** //
//                                   Misc.                                    //
// ************************************************************************** //
std::string getCurrentTime(void) {
	std::time_t now = std::time(0);
	std::tm* localTime = std::localtime(&now);
	std::stringstream ss;
	ss << std::setfill('0')
	   << (1900 + localTime->tm_year) << "-"
	   << std::setw(2) << (1 + localTime->tm_mon) << "-"
	   << std::setw(2) << localTime->tm_mday << " "
	   << std::setw(2) << localTime->tm_hour << ":"
	   << std::setw(2) << localTime->tm_min << ":"
	   << std::setw(2) << localTime->tm_sec;
	return ss.str();
}

void	handleCtrlD(void)
{
	if (std::cin.eof())
    {
        std::cout << "\nCTRL+D detected. Exiting program..." << std::endl;
        std::exit(0);
    }
}
