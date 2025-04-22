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

/* Templates */
template <typename Container>
void printContainer(const Container &c, const std::string &label)
{
	std::cout << PURPLE << label << RESET;
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) { std::cout << *it << " ";	}
	std::cout << std::endl;
}

template <typename Container>
bool isSorted(const Container &c)
{
    if (c.empty()) return true;

    typename Container::const_iterator it = c.begin();
    typename Container::const_iterator next = it;
    ++next;

	for (; next != c.end(); ++next, ++it) {
        if (*it >= *next)
            return false;
	}
	return true;
}

template <typename Iterator, typename T>
Iterator binaryInsertPos(Iterator first, Iterator last, const T &value)
{
    typedef typename std::iterator_traits<Iterator>::difference_type diff_t;
    diff_t len = std::distance(first, last);

    while (len > 0) {
        Iterator mid = first;
        diff_t half = len / 2;
        std::advance(mid, half);

        if (value < *mid) {
            len = half;
        } else {
            std::advance(first, half + 1);
            len -= half + 1;
        }
    }
    return first;
}

template <typename List>
typename List::iterator advanceIt(List &l, int n) {
	typename List::iterator it = l.begin();
	std::advance(it, n);
	return it;
}

template <typename T>
std::list<T> vecToList(const std::vector<T> &vec) {
	std::list<T> result;
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		result.push_back(*it);
	return result;
}

template <typename T>
std::vector<T> listToVec(const std::list<T> &list) {
	std::vector<T> result;
	for (typename std::list<T>::const_iterator it = list.begin(); it != list.end(); ++it)
		result.push_back(*it);
	return result;
}
