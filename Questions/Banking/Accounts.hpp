#ifndef ACCOUNTS_HPP
#define ACCOUNTS_HPP

#include <iostream>
#include<memory>
#include "Customer.hpp"
#include "Card.hpp"
#include "Transaction.hpp"
#include <vector>
#include "AccountTypes.hpp"
#include "WrongInputException.hpp"
#include "LowBalanceException.hpp"

using Transaction_ptr= std::shared_ptr<Transaction>;
using Customer_ptr = std::shared_ptr<Customer> ;
using Card_ptr=std::shared_ptr<Card>;

class Accounts
{
    AccountTypes m_acc_types;
    long int m_Acc_no;
    static int m_next_Accno;
    std::vector<Transaction_ptr> m_transactions;
    Customer_ptr m_customer;
    Card_ptr m_card;
    long int m_current_balance{0};

    
    public: 
    Accounts() = delete;
    Accounts(const Accounts &) = delete; // disabled copy constructor
    Accounts(Accounts &&) = delete; // disabled move constructor brand new in C++11
    Accounts &operator=(const Accounts &) = delete; // disabled assignment operator
    Accounts &operator=(Accounts &&) = delete;	  // disabled assignment move operator brand new in C++11
    Accounts(
        int m_acc_types_,
        
       
        Customer_ptr m_customer_,
        
        long int m_current_balance_

        );
         ~Accounts() = default;

         std::string GetAccountTypeToString(const AccountTypes type) const;
         void setAccTypes(const AccountTypes &acc_types) { m_acc_types = acc_types; }

         long int accNo() const { return m_Acc_no; }
         void setAccNo(long int Acc_no) { m_Acc_no = Acc_no; }

         std::vector<Transaction_ptr> transactions() const { return m_transactions; }
         void setTransactions(const std::vector<Transaction_ptr> &transactions) { m_transactions = transactions; }

         Customer_ptr customer() const { return m_customer; }
         void setCustomer(const Customer_ptr &customer) { m_customer = customer; }

         Card_ptr card() const { return m_card; }
         void setCard(const Card_ptr &card) { m_card = card; }

         long int currentBalance() const { return m_current_balance; }
         void setCurrentBalance(long int current_balance) { m_current_balance = current_balance; }

         void WithdrawMoney(const long int & bal);
         void DepositMoney(const long int& bal);
         void RollBack();

         friend std::ostream &operator<<(std::ostream &os, const Accounts &rhs);

};

#endif 
