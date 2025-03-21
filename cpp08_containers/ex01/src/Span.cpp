/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/Span.hpp"

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
Span::Span(void) {
    printStr("Span default created! :D", "P");
}

Span::Span(unsigned int size) : _size(size) {
    printStr("Span default created! :D", "P");
}

Span::Span(const Span & other) {  
    *this = other;
    printStr("Span copied (deep copy unnecessary)! :D", "P");
}

Span::~Span(void) {
    printStr("Span destroyed! D:", "P");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
Span & Span::operator = (const Span & other) {
    if (this != &other) {
        this->_container = other._container;
        this->_size = other._size;
    }
    printStr("Span assigned (deep is unnecessary)! :D", "P");
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //
int   Span::getNmbr(int index) const {
    if (index >= static_cast<int>(_size))
        throw std::out_of_range("Out of range!");
    return _container[index];
}

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
void    Span::addNmbr(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_container.size() + std::distance(begin, end) > _size)
        throw Span::ContainerFullException();
    _container.insert(_container.end(), begin, end);

}

void   Span::addNmbr(int nmbr) {
    if (_container.size() >= _size)
        throw Span::ContainerFullException();
    _container.push_back(nmbr);

}

int     Span::shortestSpan(void) const
{
    if (_container.size() <= 1)
        throw Span::ContainerEmptyException();
    try {
        std::vector<int> shortest(_size);
        std::vector<int> tmp = _container;  // func is const, so need to make copy
        std::sort(tmp.begin(), tmp.end());
        std::adjacent_difference(tmp.begin(), tmp.end(), shortest.begin()); // puts 1st element unchanged so need + 1
        std::vector<int>::iterator it = std::min_element(shortest.begin() + 1, shortest.end()); 
        return *it;
    } catch (std::exception & e) {
        printStr(e.what(), "R");
    }
    return 0;
}

int Span::longestSpan(void) const
{
    if (_container.size() <= 1)
        throw Span::ContainerEmptyException();

    int max = *std::max_element(_container.begin(), _container.end());
    int min = *std::min_element(_container.begin(), _container.end());
    return max - min;
}

const char* Span::ContainerFullException::what(void) const throw() {
    static std::string msg = std::string(RED) + "Container can't take more, aborting 💀" 
                                                        + std::string(RESET);
    return msg.c_str();
}

const char* Span::ContainerEmptyException::what(void) const throw() {
    static std::string msg = std::string(RED) + "Container is empty! 💀" 
                                                        + std::string(RESET);
    return msg.c_str();
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
