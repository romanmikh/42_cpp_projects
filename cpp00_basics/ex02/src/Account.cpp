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

Account::Account(int initial_deposit) : _amount(initial_deposit), \
                                        _nbDeposits(0), \
                                        _nbWithdrawals(0)
{
    this->_accountIndex = _nbAccounts;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
                << ";amount:" << _amount 
                << ";created" << std::endl;

    _nbAccounts += 1;
    _totalAmount += _amount;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
                << ";amount:" << _amount 
                << ";closed" << std::endl;
}

// ************************************************************************** //
//                              Operations                                    //
// ************************************************************************** //
void	Account::displayAccountsInfos( void )
{
    // removed static. static class but not static instance...
    // accounts:8;total:20049;deposits:0;withdrawals:0
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() 
                << ";total:" << getTotalAmount() 
                << ";deposits:" << getNbDeposits() 
                << ";withdrawals:" << getNbWithdrawals() 
                << std::endl;
}

void	Account::displayStatus( void ) const
{
    // index:0;amount:47;deposits:1;withdrawals:0
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
                << ";amount:" << _amount 
                << ";deposits:" << _nbDeposits 
                << ";withdrawals:" << _nbWithdrawals 
                << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    _totalAmount += deposit;
    _amount += deposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
                << ";p_amount:" << _amount - deposit
                << ";deposit:" << deposit 
                << ";amount:" << _amount 
                << ";nb_deposits:" << _nbDeposits
                << std::endl;
    
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _amount -= withdrawal;
    _displayTimestamp();
    if (checkAmount() == 1)
    {
        _nbWithdrawals += 1;
        _totalNbWithdrawals += 1;
        _totalAmount -= withdrawal;
        std::cout << " index:" << _accountIndex 
                    << ";p_amount:" << _amount + withdrawal
                    << ";withdrawal:" << withdrawal 
                    << ";amount:" << _amount
                    << ";nb_withdrawals:" << _nbWithdrawals
                    << std::endl;
        return true;
    }
    else 
    {
        _amount += withdrawal;
        std::cout << " index:" << _accountIndex 
                    << ";p_amount:" << _amount
                    << ";withdrawal:" << "refused"
                    << std::endl;
    }
    return false;
}

int		Account::checkAmount( void ) const
{
    if (_amount  < 0)
        return 0;
    return 1;
}

void	Account::_displayTimestamp( void )
{
    std::cout << "[20250304_091532]";
    return ;
}

// ************************************************************************** //
//                                  Accessors                                 //
// ************************************************************************** //
int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

// ************************************************************************** //
//              statics, called once, only when program starts                //
// ************************************************************************** //
int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;