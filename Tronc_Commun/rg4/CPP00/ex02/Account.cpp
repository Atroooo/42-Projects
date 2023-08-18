/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atro <atro@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:41:09 by atro              #+#    #+#             */
/*   Updated: 2023/08/18 11:56:17 by atro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit)
{
    this->_totalAmount = initial_deposit;
    this->_nbAccounts = 0;
    this->_totalNbDeposits = 0;
    this->_totalNbWithdrawals = 0;
    this->_accountIndex = 0;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
}

Account::~Account(void)
{
    return ;
}

void Account::_displayTimestamp(void)
{
    return ;
}

int Account::getNbAccounts(void)
{
    return (this->_nbAccount);
}

int Account::getTotalAmount(void)
{
    return (this->_totalAmount)
}

int Account::getNbDeposits(void)
{
    return ;
}

int Account::getNbWithdrawals(void)
{
    return ;
}

void Account::displayAccountsInfos(void)
{
    return ;    
}

void Account::makeDeposit(int deposit)
{
    return ;
}

bool Account::makeWithdrawal(int withdrawal)
{
    return ;
}

int Account::checkAmount(void) const
{
    return ;
}

void    Account::displayStatus(void) const
{
    return ;
}
