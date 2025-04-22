/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Utils.hpp"

/* non-member functions & operators */

class BitcoinExchange {
    
    protected:

    private:
        std::map<std::string, float> loadExchangeRates(const char *filename) const;
        bool parseLine(const std::string &line, std::string &date, std::string &valueStr) const;
        void processEntry(const std::string &date, const std::string &valueStr, const std::map<std::string, float> &rates) const;
    

    public:

        /* construcotrs & destructors */
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange(void);

        /* operator overloads */
        BitcoinExchange & operator = (const BitcoinExchange &other);
        
        /* accessors */

        /* member functions */
        bool            readData(const char *filename, std::ifstream &file) const;
        // int             isFileEmpty(std::ifstream &file) const;
        void            printFile(std::string fileName) const;
        void            processFile(std::string fileName) const;

        /* static values */

        /* nested classes */

};
