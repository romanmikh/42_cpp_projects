/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

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
ScalarConverter::ScalarConverter(void) {
    printStr("ScalarConverter default created! :D", "P");
}

ScalarConverter::ScalarConverter(const ScalarConverter & other) {  
    *this = other;
    printStr("ScalarConverter copied (deep copy unnecessary)! :D", "P");
}

ScalarConverter::~ScalarConverter(void){
    printStr("ScalarConverter destroyed! D:", "P");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
ScalarConverter & ScalarConverter::operator = (const ScalarConverter & other) {
    if (this != &other) {
        printStr("ScalarConverter assigned (deep is unnecessary)! :D", "P");
    }
    return *this;
}


// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
bool ScalarConverter::_handlePseudoLiterals(const std::string str, float vFloat, 
                                                            double vDouble) {
    if (str == "-inff" || str == "+inff" || str == "inff" ||str == "nanf") {
        vFloat = static_cast<float>(atof(str.c_str()));
        std::cout << "int: impossible" << std::endl;
        std::cout << "char: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << static_cast<double>(vFloat) << std::endl;
        return 1;
    }
    if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan") {
        vDouble = static_cast<double>(atof(str.c_str()));
        std::cout << "int: impossible" << std::endl;
        std::cout << "char: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(vDouble) << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
        return 1;
    }
    return 0;
}

void ScalarConverter::convert(const std::string &str) {
    int vInt = 0;
    float vFloat = 0.0f;
    double vDouble = 0.0;
    
    if (_handlePseudoLiterals(str, vFloat, vDouble))
        return;

    if (str.length() == 1 && !isdigit(str[0]) && str[0] >= 32 && str[0] <= 126) {
        vInt = static_cast<int>(str[0]);
        std::cout << "int: " << vInt << std::endl;
        std::cout << "char: '" << str[0] << "'" << std::endl;
        vFloat = static_cast<float>(vInt);
        vDouble = static_cast<double>(vInt);
    } else {
        std::istringstream iss(str);
        iss >> vInt;
        std::cout << "int: " << static_cast<int>(vInt) << std::endl;
        if (vInt >= 32 && vInt <= 126)
            std::cout << "char: '" << static_cast<char>(vInt) << "'" << std::endl;
        else if (vInt >= 0 && vInt <= 255)
            std::cout << "char: Non displayable (32 < c < 126)" << std::endl;
        else
            std::cout << "char: impossible (32 < c < 255)" << std::endl;

        iss.clear();
        iss.str(str);
        iss >> vFloat;
        iss.clear();
        iss.str(str);
        iss >> vDouble;
    }

    std::cout << std::fixed;
    std::cout << "float: " << vFloat << "f" << std::endl;
    std::cout << "double: " << vDouble << std::endl;
}

const char *	ScalarConverter::ImpossibleException::what(void) const throw()
{
	static std::string msg = std::string(RED) 
            + "Input is not printable 💀" + std::string(RESET);
    return msg.c_str();
}
// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
