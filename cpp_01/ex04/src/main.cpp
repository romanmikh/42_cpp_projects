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

int 	isFileEmpty(std::ifstream &file) {
	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
		return 1;
	file.seekg(0, std::ios::beg);  // Reset position back to the beginning
	return 0;
}

void 	printFile(std::string fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file) {
		std::cerr << "> Error: cannot open " << fileName 
					<< " for reading." << std::endl;
		return ;
	}

	std::string newLine;
	while (std::getline(file, newLine)) {
		std::cout << newLine << std::endl;
	}
	file.close();
}

void myReplace(std::ifstream &file, std::ofstream &newFile, \
				std::string s1, std::string s2) {
	std::string line;

	while (std::getline(file, line)) {
		std::string updatedLine;
		size_t pos = 0, lastPos = 0;
		
		while ((pos = line.find(s1, lastPos)) != std::string::npos) {
			updatedLine += line.substr(lastPos, pos - lastPos);
			updatedLine += s2;
			lastPos = pos + s1.length();
		}
		updatedLine += line.substr(lastPos); // Append remainder of line
		newFile << updatedLine << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "> Error: provide file, s1 and s2." << std::endl;
		return (1);
	}
	std::string filename = argv[1], s1 = argv[2], s2 = argv[3];
	std::string newFilename = filename + ".replace";
	std::cout << "> Copying " << filename << "..." << std::endl;

    std::ifstream file(filename.c_str());
	std::ofstream newFile(newFilename.c_str());
    if (!file) {
        std::cerr << "> Error: cannot open " << filename 
					<< " for reading. Try 'chmod 600 file'" << std::endl;
        return 1;
    }
	else if (isFileEmpty(file)) {
		std::cerr << "> Error: " << filename << " is empty." << std::endl;
		return 1;
	}
    if (!newFile) {
        std::cerr << "> Error: cannot create" << newFilename << std::endl;
        return 1;
    }
	myReplace(file, newFile, s1, s2);
	file.close();
	newFile.close();

	std::string view;
    std::cout << "> Created " << filename << ".replace!" << std::endl;
	std::cout << "> Would you like to see it? y or n: ";
	std::cin >> view;
	if (view == "y")
		printFile(newFilename);
	return (0);
}
