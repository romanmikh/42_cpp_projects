/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../inc/Utils.hpp"

class PmergeMe {

    public:

        /* construcotrs & destructors */
        PmergeMe(void);
        PmergeMe(const PmergeMe &);
        ~PmergeMe(void);

        /* operator overloads */
        PmergeMe & operator = (const PmergeMe &);

        /* member functions */
        int         jacobsthal(int n);

        void            sortVec(const std::string &);
        void            mergeVec(std::vector<int> &vec1, std::vector<int> &vec2, int left, int mid, int right);
        void            mergeSortVec(std::vector<int> &vec1, std::vector<int> &vec2, int left, int right);
        std::vector<int> smallSortVec(const std::vector<int> &A, const std::vector<int> &B);

        void            sortList(const std::string &);
        void            mergeList(std::list<int> &vec1, std::list<int> &vec2, int left, int mid, int right);
        // void            mergeSortList(std::list<int> &vec1, std::list<int> &vec2, int left, int right);
        std::list<int>  smallSortList(const std::list<int> &A, const std::list<int> &B);
        void            mergeSortList(std::list<int> &list1, std::list<int> &list2);
};
