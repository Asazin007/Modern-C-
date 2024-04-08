#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP
#include "NoTransactionException.hpp"
#include "Accounts.hpp"

using Account_ptr= std::shared_ptr<Accounts>;
using container = std::vector<Account_ptr>;

void CreateAccount();
void CheckBalance();
 void CheckDetails();
Account_ptr getaccount();
void Withdraw();
void Deposit();
void RollBack();



#endif // FUNCTIONALITIES_HPP
