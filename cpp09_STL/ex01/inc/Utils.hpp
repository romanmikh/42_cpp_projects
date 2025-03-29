/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* Standard Input/Output */
#include <cstdio>
#include <iostream>

/* Standard Library */
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <csignal>
#include <cassert>

/* String & Stream */
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>

/* Algorithms & Utilities */
#include <numeric>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>

/* Containers */
#include <set>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <iterator>

/* Exception Handling */
#include <limits>
#include <stdexcept>
#include <exception>

/* Time */
#include <ctime>


void	        handleCtrlD(void);
unsigned int    getUnsignedInt(const std::string& prompt);
void            printStr(const std::string& text, const std::string& colour = "RESET");