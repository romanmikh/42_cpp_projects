/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* Standard Input/Output */
#include <cstdio>
#include <iostream>

/* Standard Library */
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <csignal>
#include <cassert>

/* String & Stream */
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>

/* Algorithms & Utilities */
#include <numeric>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>

/* Containers */
#include <set>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <iterator>

/* Exception Handling */
#include <limits>
#include <stdexcept>
#include <exception>

/* Time */
#include <ctime>

/* Strings */
std::vector<std::string>    split(const std::string& str, char delimiter);
std::vector<std::string>    splitByStr(const std::string& str, const std::string& delim);
std::string                 trim(const std::string&);
void                        printStr(const std::string& text, const std::string& colour = "RESET");

/* Conversions */
std::string                 intToString(int value);
std::string                 uintToString(unsigned int value);
std::string                 boolToString(bool value);
std::string                 sizeToString(size_t value);
bool                        parseInt(const std::string& s, int& out);
bool                        parseFloat(const std::string& s, float& out);
unsigned int                getUnsignedInt(const std::string& prompt);
int                         dateToInt(const std::string &date);
int                         strToInt(const std::string &str);
float                       strToFloat(const std::string &str);


/* Validations */
bool                        isValidDate(const std::string& date);
bool                        isInteger(const std::string& s);
bool                        isFloat(const std::string& s);
int                         isFileEmpty(std::ifstream &file);
void                        printFile(std::string fileName);
bool                        isValidFile(const char *filename, std::ifstream &file);

/* Misc */
std::string                 getCurrentTime(void);
void	                    handleCtrlD(void);


/* Colours */
#define RESET   "\e[0m"
#define RED     "\e[31m"
#define GREEN   "\e[32m"
#define YELLOW  "\e[33m"
#define BLUE    "\e[34m"
#define PURPLE  "\e[35m"
#define CYAN    "\e[36m"
#define WHITE   "\e[37m"
#define BRED    "\e[1;31m"
#define BGREEN  "\e[1;32m"
#define BYELLOW "\e[1;33m"
#define BBLUE   "\e[1;34m"
#define BPURPLE "\e[1;35m"
#define BCYAN   "\e[1;36m"
#define BGR     "\e[41m"
#define BGG     "\e[42m"
#define BGY     "\e[43m"
#define BGB     "\e[44m"
#define BGP     "\e[45m"
#define BGC     "\e[46m"
#define BGW     "\e[47m"