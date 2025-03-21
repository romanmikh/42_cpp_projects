/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include "../inc/Utils.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

int rands(void) { return std::rand(); }  //  % 1000000000; }

struct printWithComa {
    void operator()(int nmbr) { std::cout << nmbr << ", "; }
};

int main(void)
{
    unsigned int    N = 100000000;
    Span            span(N);
    int             nToAdd = 10000000;

    std::vector<int>    v(nToAdd);
    std::generate(v.begin(), v.end(), rands);
    std::cout << std::endl << "Adding " << nToAdd << " numbers to container size: " 
                                     << N << std::endl << std::endl;
    
    /* fill container */
    try {
        span.addNmbr(v.begin(), v.end());
        std::cout << GREEN << "Added! " << RESET << std::endl;
    } catch (std::exception & e) {
        printStr(e.what(), "R");
    }

    /* print */
    // try {
    //     std::cout << std::endl << "[";
    //     std::for_each(v.begin(), v.end(),printWithComa());
    //     std::cout << "]" << std::endl << std::endl;
    // } catch (std::exception & e) {
    //     printStr(e.what(), "R");
    // }

    try {
        std::cout << CYAN << "Shortest span: " << RESET << span.shortestSpan();
        std::cout << CYAN << ", longest span: " << RESET << span.longestSpan() << std::endl << std::endl;
    } catch (std::exception & e) {
        printStr(e.what(), "R");
    }

    return 0;
}
