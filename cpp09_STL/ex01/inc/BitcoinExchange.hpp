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

    public:

        /* construcotrs & destructors */
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange(void);

        /* operator overloads */
        BitcoinExchange & operator = (const BitcoinExchange &other);
        
        /* accessors */

        /* member functions */
        void            readData(const char *filename);
        int             isFileEmpty(std::ifstream &file);
        void            printFile(std::string fileName);

        /* static values */

        /* nested classes */

};
