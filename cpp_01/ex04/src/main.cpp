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

#include <string>
#include <iostream>
#include <fstream>

// void    printFile(std::string filename)
// {
//     std::ifstream file(filename.c_str());
//     if (!file) {
//         std::cerr << "Error: cannot open" << filename << std::endl;
//         return ;
//     }

//     if (file.is_open())
//         std::cout << file.rdbuf();

//     file.close();
// }

// void copyFile(std::string filename)
// {
//     std::cout << "Copying file..." << std::endl;
//     std::ifstream file(filename.c_str());
//     if (!file) {
//         std::cerr << "Error: cannot open" << filename << std::endl;
//         return std::ofstream();
//     }
//     printFile(filename);

//     std::ofstream newFile(newFilename.c_str());
//     if (!newFile) {
//         std::cerr << "Error: cannot create" << newFilename << std::endl;
//         return std::ofstream();
//     }
//     std::cout << "Created newFile!" << std::endl;
//     return newFile;
// }


int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Error: provide file, s1 and s2." << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string newFilename = filename + ".replace";
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	// -----------------------------------------------------------------------
	std::cout << "Copying file..." << std::endl;
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: cannot open" << filename << std::endl;
        return 1;
    }
	std::ofstream newFile(newFilename.c_str());
    if (!newFile) {
        std::cerr << "Error: cannot create" << newFilename << std::endl;
        return 1;
    }
    std::cout << "Created newFile!" << std::endl;
	if (file.is_open())
//         std::cout << file.rdbuf();
	// -----------------------------------------------------------------------
	(void)s1;
	(void)s2;


	return (0);
}
