/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialiser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serialiser.hpp"
#include "../inc/Utils.hpp"

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
Serialiser::Serialiser(void) {
    printStr("serialiser default created! :D", "P");
}

Serialiser::Serialiser(const Serialiser & other) {  
    *this = other;
    printStr("serialiser copied (deep copy unnecessary)! :D", "P");
}

Serialiser::~Serialiser(void){
    printStr("serialiser destroyed! D:", "P");
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
Serialiser & Serialiser::operator = (const Serialiser & other) {
    if (this != &other) {
        printStr("serialiser assigned (deep is unnecessary)! :D", "P");
    }
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
uintptr_t Serialiser::serialise(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialiser::deserialise(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
