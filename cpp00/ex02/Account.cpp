/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void ){
    return Account::_nbAccounts;
}

int Account::getTotalAmount( void ){
    return Account::_totalAmount;
}

int Account::getNbDeposits( void ){
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals( void ){
    return Account::_totalNbWithdrawals;
}

void Account::_displayTimestamp( void ){
    std::time_t timestamp = std::time(0);
    tm *time = localtime(&timestamp);
    std::cout << "[";
    std::cout << time->tm_year + 1900;
    if (time->tm_mon + 1 <= 9)
        std::cout << "0";
    std::cout << time->tm_mon + 1;
    if (time->tm_mday <= 9)
        std::cout << "0";
    std::cout << time->tm_mday;
    std::cout << "_";
    if (time->tm_hour <= 9)
        std::cout << "0";
    std::cout << time->tm_hour;
    if (time->tm_min <= 9)
        std::cout << "0";
    std::cout << time->tm_min;
    if (time->tm_sec <= 9)
        std::cout << "0";
    std::cout << time->tm_sec;
    std::cout << "] ";
}

Account::Account( int initial_deposit ){
    this->_accountIndex = Account::_nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";" << "created\n";

    Account::_totalAmount += this->_amount;
}

Account::~Account(void){
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";" << "closed\n";
    Account::_totalAmount += this->_amount;
    --Account::_nbAccounts;
}

void Account::displayAccountsInfos( void ){
    _displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";";
    std::cout << "total:" << Account::_totalAmount << ";";
    std::cout << "deposits:" << Account::_totalNbDeposits << ";";
    std::cout << "withdrawals:" << Account::_totalNbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit){
    ++this->_nbDeposits;
    Account::_totalNbDeposits += 1;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount + deposit << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << "\n";
    this->_amount += deposit;
    Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal( int withdrawal ){
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:";
    if (this->_amount < withdrawal){
        std::cout << "refused\n";
        return false;
    }
    std::cout << withdrawal << ";";
    std::cout << "amount:" << this->_amount - withdrawal << ";";
    std::cout << "nb_withdrawals:" << ++this->_nbWithdrawals << "\n";
    ++Account::_totalNbWithdrawals;
    Account::_totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    return true;
}

int Account::checkAmount( void ) const{
    return this->_amount;
}


void Account::displayStatus( void ) const{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";
}
