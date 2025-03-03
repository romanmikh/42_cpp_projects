/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:43:01 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 16:02:54 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "../inc/Account.hpp"

Account::Account(int initial_deposit)
{
    std::cout << "Account constructor called" << std::endl;

    _nbAccounts = 0;
}

Account::~Account(void)
{
    std::cout << "Account destructor called" << std::endl;
}

// ************************************************************************** //
// operations
// ************************************************************************** //
static void	displayAccountsInfos( void );

void	makeDeposit( int deposit );
bool	makeWithdrawal( int withdrawal );
int		checkAmount( void ) const;
void	displayStatus( void ) const;


static void	_displayTimestamp( void )
{
    std::cout << "[time_stamp] " << std::endl;
    return ;
}

// ************************************************************************** //
// getters & setters
// ************************************************************************** //
static int	getNbAccounts( void )
{
    return Account::_nbAccounts;
}

static int	getTotalAmount( void )
{
    return _totalAmount;
}

static int	getNbDeposits( void )
{
    return _totalNbDeposits;
}

static int	getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

int Account::_nbAccounts = 0;