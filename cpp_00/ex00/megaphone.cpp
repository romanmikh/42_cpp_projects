/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:53:38 by rocky             #+#    #+#             */
/*   Updated: 2024/08/25 18:53:43 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	std::cout << c;
}

void upper(char **argv)
{
	int i;

	while (*argv)
	{
		i = 0;
		while ((*argv)[i])
		{
			to_upper((*argv)[i]);			
			i++;
		}
		argv++;
	}
	std::cout << "\n";
}

int main(int argc, char **argv)
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		upper(argv + 1);
	return (0);
}

