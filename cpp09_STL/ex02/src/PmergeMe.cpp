/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

// ************************************************************************** //
//             Orthodox Canonical Constructors & Desctructors                 //
// ************************************************************************** //
PmergeMe::PmergeMe(void) {}


PmergeMe::~PmergeMe(void){}

PmergeMe::PmergeMe(const PmergeMe & other) {
    *this = other;
}

// ************************************************************************** //
//                           Operator Overloads                               //
// ************************************************************************** //
PmergeMe & PmergeMe::operator = (const PmergeMe & other) {
    if (this != &other)
        *this = other;
    return *this;
}

// ************************************************************************** //
//                               Accessors                                    //
// ************************************************************************** //

// ************************************************************************** //
//                             Public Functions                               //
// ************************************************************************** //
void merge(std::vector<int> &vec1, std::vector<int> &vec2, int left, int mid, int right) {
	std::vector<int> temp1, temp2;
	int i = left, j = mid + 1;

	while (i <= mid && j <= right) {
		if (vec1[i] <= vec1[j]) {
			temp1.push_back(vec1[i]);
			temp2.push_back(vec2[i]);
			++i;
		} else {
			temp1.push_back(vec1[j]);
			temp2.push_back(vec2[j]);
			++j;
		}
	}
	while (i <= mid) {
		temp1.push_back(vec1[i]);
		temp2.push_back(vec2[i]);
		++i;
	}
	while (j <= right) {
		temp1.push_back(vec1[j]);
		temp2.push_back(vec2[j]);
		++j;
	}
	for (int k = 0; k < static_cast<int>(temp1.size()); ++k) {
		vec1[left + k] = temp1[k];
		vec2[left + k] = temp2[k];
	}
}

bool isSorted(const std::vector<int> &vec) {
	for (std::size_t i = 1; i < vec.size(); ++i) {
		if (vec[i] < vec[i - 1]) {
			return false;
		}
	}
	return true;
}

void mergeSort(std::vector<int> &vec1, std::vector<int> &vec2, int left, int right) {
	if (left >= right) return;

	int mid = (left + right) / 2;
	mergeSort(vec1, vec2, left, mid);
	mergeSort(vec1, vec2, mid + 1, right);
	merge(vec1, vec2, left, mid, right);
}

void fit(std::vector<int> &vec, int n) {
	int i = 0;
	while (n > vec[++i]) {	continue; }
	vec.insert(vec.begin() + i, n);
}

void 	PmergeMe::sort(const std::string & expression) {
	std::vector<std::string> tokens = split(expression, ' ');
	std::vector<int> larger;
	std::vector<int> smaller;
	std::vector<int> sorted;
	std::istringstream iss(expression);
	std::string token;

	// ******************************* ***************************** //
	// Check input & make smaller + bigger stacks
	// ******************************* ***************************** //
	for (std::size_t i = 0; i + 1 < tokens.size(); i += 2) {
		int a = strToInt(tokens[i]);
		int b = strToInt(tokens[i + 1]);

		if (!isInteger(tokens[i]) || !isInteger(tokens[i + 1]) ||
			std::find(smaller.begin(), smaller.end(), a) != smaller.end() ||
			std::find(smaller.begin(), smaller.end(), b) != smaller.end() ||
			std::find(larger.begin(), larger.end(), a) != larger.end() ||
			std::find(larger.begin(), larger.end(), b) != larger.end())
		{
			return printStr("Error: Only positive integers without repeats accepted", RED);
		}
		if (a > b) {
			larger.push_back(a); smaller.push_back(b);
		} else {
			larger.push_back(b); smaller.push_back(a);
		}
	}	

	// ******************************* ***************************** //
	// sort the larger stack recursively
	// ******************************* ***************************** //
	mergeSort(larger, smaller, 0, larger.size() - 1);

	// ******************************* ***************************** //
	// Ford - Johnson algorithm
	// ******************************* ***************************** //
	sorted.push_back(smaller[0]); sorted.push_back(larger[0]); sorted.push_back(larger[1]);
	smaller.erase(smaller.begin()); larger.erase(larger.begin(), larger.begin() + 2);

	while (larger.size() > 2)
	{
		fit(sorted, smaller[1]); smaller.erase(smaller.begin() + 1);
		fit(sorted, smaller[0]); smaller.erase(smaller.begin());
		sorted.push_back(larger[0]); larger.erase(larger.begin());
		sorted.push_back(larger[0]); larger.erase(larger.begin());
	}

	sorted.push_back(larger[0]); larger.erase(larger.begin());
	while (!smaller.empty()) {
		std::size_t last = smaller.size() - 1;
		fit(sorted, smaller[last]);
		smaller.erase(smaller.begin() + last);
	}
	sorted.push_back(larger[0]); larger.erase(larger.begin());

	std::cout << PURPLE << "Sorted: " << RESET;
	for (std::size_t i = 0; i < sorted.size(); ++i) {
		std::cout << sorted[i] << " ";
	}
	std::cout << std::endl;

	if (!isSorted(sorted)) {
		printStr("Error: Not sorted", RED);
	} else {
		printStr("Success: Sorted", GREEN);
	}
}

// ************************************************************************** //
//                             Private Functions                              //
// ************************************************************************** //

// ************************************************************************** //
//                            Non-member Functions                            //
// ************************************************************************** //
