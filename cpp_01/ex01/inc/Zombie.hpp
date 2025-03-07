/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:26:49 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:16:28 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

#include <string>
#include <iostream>

class Zombie {

public:

    Zombie(void);  // added for zombieHorde
    Zombie(std::string name);
    ~Zombie(void);

    void        announce(void);
    void        setName(std::string name);

private:

    std::string _name;
    std::string _getName(void) const;

};

Zombie*         newZombie(std::string name);
void            randomChump(std::string name);
Zombie*         zombieHorde(int N, std::string name);
void            freeHorde(Zombie *horde);

#endif