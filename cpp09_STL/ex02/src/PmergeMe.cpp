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
//        Orthodox Canonical Constructors, Desctructors & Overloads           //
// ************************************************************************** //
PmergeMe::PmergeMe(void) {}


PmergeMe::~PmergeMe(void){}

PmergeMe::PmergeMe(const PmergeMe & other) {
    *this = other;
}

PmergeMe & PmergeMe::operator = (const PmergeMe & other) {
    if (this != &other)
        *this = other;
    return *this;
}

// ************************************************************************** //
//                           shared functions                                 //
// ************************************************************************** //
int PmergeMe::jacobsthal(int n) {
	// (2**n - (-1)**n) // 3
	if (n == 0) return 0;
	int exp = 1 << n; // 2**n
	int res = (n % 2) ? -1 : 1; // (-1)**n
	return (exp - res) / 3;
}

// ************************************************************************** //
//                             vector approach                                //
// ************************************************************************** //
void PmergeMe::mergeVec(std::vector<int> &vec1, std::vector<int> &vec2, int left, int mid, int right) {
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

void PmergeMe::mergeSortVec(std::vector<int> &vec1, std::vector<int> &vec2, int left, int right) {
	if (left >= right) return;

	int mid = (left + right) / 2;
	mergeSortVec(vec1, vec2, left, mid);
	mergeSortVec(vec1, vec2, mid + 1, right);
	mergeVec(vec1, vec2, left, mid, right);
}

std::vector<int> PmergeMe::smallSortVec(const std::vector<int> &A, const std::vector<int> &B) {
	std::vector<int> result = A;
	result.insert(result.end(), B.begin(), B.end());

	for (std::size_t i = 0; i < result.size(); ++i) {
		std::size_t min = i;
		for (std::size_t j = i + 1; j < result.size(); ++j)
			if (result[j] < result[min]) min = j;
		if (min != i) {
			int tmp = result[i];
			result[i] = result[min];
			result[min] = tmp;
		}
	}
	return result;
}

void 	PmergeMe::sortVec(const std::string & expression) {
	std::vector<std::string> tokens = split(expression, ' ');
	std::vector<int> A;
	std::vector<int> B;
	std::vector<int> sorted;
	std::istringstream iss(expression);
	std::string token;

	// ************************************************************* //
	// Check input & make A & B containers
	// ************************************************************* //
	for (std::size_t i = 0; i + 1 < tokens.size(); i += 2) {
		int a = strToInt(tokens[i]);
		int b = strToInt(tokens[i + 1]);

		if (!isInteger(tokens[i]) || !isInteger(tokens[i + 1]) ||
			std::find(B.begin(), B.end(), a) != B.end() ||
			std::find(B.begin(), B.end(), b) != B.end() ||
			std::find(A.begin(), A.end(), a) != A.end() ||
			std::find(A.begin(), A.end(), b) != A.end())
		{
			return printStr("Error: Only positive integers without repeats accepted", RED);
		}
		if (a > b) {
			A.push_back(a); B.push_back(b);
		} else {
			A.push_back(b); B.push_back(a);
		}
	}	
	if (tokens.size() % 2 == 1) {
		int last = strToInt(tokens.back());
		B.push_back(last);
	}

	if (tokens.size() <= 4)
	{
		sorted = smallSortVec(A, B);
		if (!isSorted(sorted)) {
			printStr("Error: Not sorted / has repeats", RED);
		} else {
			printContainer(sorted, "Vectors:  ");
		}
		return;
	}
	
	// ************************************************************* //
	// Sort container B recursively using merge sort
	// ************************************************************* //
	mergeSortVec(A, B, 0, A.size() - 1);

	std::vector<int> jacobsthalOrder;
	int i = 2;
	while (jacobsthal(i) < (static_cast<int>(B.size()))) {
		jacobsthalOrder.push_back(jacobsthal(i++));
	}
	jacobsthalOrder.push_back(jacobsthal(i));

	// ************************************************************* //
	// Ford - Johnson algorithm: 
	// binaryInsert B into sorted A in the Jacobsthal order
	// ************************************************************* //
	sorted.push_back(B[0]);
	while (!A.empty())	{
		sorted.push_back(*A.begin()); A.erase(A.begin());
	}

	std::vector<int>::const_iterator it = jacobsthalOrder.begin();
	std::vector<int>::const_iterator next = it;
	next++;

	for (; next != jacobsthalOrder.end(); ++it, ++next) {
		size_t  blockStart = *it;
		size_t  blockEnd = *next;
		if (blockStart < B.size() && blockEnd > B.size()) {
			blockEnd = B.size();
		}
		while (blockStart != blockEnd) {
			sorted.insert(binaryInsertPos(sorted.begin(), sorted.end(), B[blockEnd - 1]), B[blockEnd - 1]);
			blockEnd--;
		}
	}

	if (!isSorted(sorted)) {
		printStr("Error: Not sorted / has repeats", RED);
	} else {
		printContainer(sorted, "Vectors:  ");
	}
}




// ************************************************************************** //
//                             list approach                                  //
// ************************************************************************** //
void PmergeMe::mergeSortList(std::list<int> &list1, std::list<int> &list2) {
	std::list<std::pair<int, int> > pairs;
	std::list<int>::iterator it1 = list1.begin();
	std::list<int>::iterator it2 = list2.begin();
	while (it1 != list1.end()) {
		pairs.push_back(std::make_pair(*it1, *it2));
		++it1;
		++it2;
	}

	int odd = -1;
	if (it2 != list2.end()) {
		odd = (*it2);

	}
	for (std::list<std::pair<int, int> >::iterator i = pairs.begin(); i != pairs.end(); ++i) {
		std::list<std::pair<int, int> >::iterator min = i;
		for (std::list<std::pair<int, int> >::iterator j = i; j != pairs.end(); ++j) {
			if (j->first < min->first)
				min = j;
		}
		if (min != i)
			std::swap(*i, *min);
	}
	list1.clear();
	list2.clear();
	for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
		list1.push_back(it->first);
		list2.push_back(it->second);
	}
	if (odd != -1) {
		list2.push_back(odd);
	}
}


std::list<int> PmergeMe::smallSortList(const std::list<int> &A, const std::list<int> &B) {
	std::list<int> result = A;
	result.insert(result.end(), B.begin(), B.end());

	for (std::list<int>::iterator it1 = result.begin(); it1 != result.end(); ++it1) {
		std::list<int>::iterator min = it1;
		for (std::list<int>::iterator it2 = it1; it2 != result.end(); ++it2) {
			if (*it2 < *min)
				min = it2;
		}
		if (min != it1) {
			int temp = *it1;
			*it1 = *min;
			*min = temp;
		}
	}
	return result;
}

void 	PmergeMe::sortList(const std::string & expression) {
	std::vector<std::string> tokens = split(expression, ' ');
	std::list<int> A;
	std::list<int> B;
	std::list<int> sorted;
	std::istringstream iss(expression);
	std::string token;

	// ************************************************************* //
	// Check input & make A & B containers
	// ************************************************************* //
	for (std::size_t i = 0; i + 1 < tokens.size(); i += 2) {
		int a = strToInt(tokens[i]);
		int b = strToInt(tokens[i + 1]);

		if (!isInteger(tokens[i]) || !isInteger(tokens[i + 1]) ||
			std::find(B.begin(), B.end(), a) != B.end() ||
			std::find(B.begin(), B.end(), b) != B.end() ||
			std::find(A.begin(), A.end(), a) != A.end() ||
			std::find(A.begin(), A.end(), b) != A.end())
		{
			return printStr("Error: Only positive integers without repeats accepted", RED);
		}
		if (a > b) {
			A.push_back(a); B.push_back(b);
		} else {
			A.push_back(b); B.push_back(a);
		}
	}	
	if (tokens.size() % 2 == 1) {
		int last = strToInt(tokens.back());
		B.push_back(last);
	}

	if (tokens.size() <= 4)
	{
		sorted = smallSortList(A, B);
		if (!isSorted(sorted)) {
			printStr("Error: Not sorted / has repeats", RED);
		} else {
			printContainer(sorted, "Lists:    ");
		}
		return;
	}
	
	// ************************************************************* //
	// Sort container B recursively using merge sort
	// ************************************************************* //
	mergeSortList(A, B);

	std::list<int> jacobsthalOrder;
	int i = 2;
	while (jacobsthal(i) < (static_cast<int>(B.size()))) {
		jacobsthalOrder.push_back(jacobsthal(i++));
	}
	jacobsthalOrder.push_back(jacobsthal(i));

	// ************************************************************* //
	// Ford - Johnson algorithm: 
	// binaryInsert B into sorted A in the Jacobsthal order
	// ************************************************************* //
	sorted.push_back(*B.begin()); //B.erase(B.begin());
	while (!A.empty())	{
		sorted.push_back(*A.begin()); A.erase(A.begin());
	}

	std::list<int>::const_iterator it = jacobsthalOrder.begin();
	std::list<int>::const_iterator next = it;
	++next;

	for (; next != jacobsthalOrder.end(); ++it, ++next) {
		size_t  blockStart = *it;
		size_t  blockEnd = *next;
		if (blockStart < B.size() && blockEnd > B.size()) {
			blockEnd = B.size();
		}
		while (blockStart != blockEnd) {
			std::list<int>::iterator b_it = B.begin();
			std::advance(b_it, blockEnd - 1);
			int value = *b_it;
			sorted.insert(binaryInsertPos(sorted.begin(), sorted.end(), value), value);
			blockEnd--;
		}
	}

	if (!isSorted(sorted)) {
		printStr("Error: Not sorted / has repeats", RED);
	} else {
		printContainer(sorted, "Lists:    ");
	}
}