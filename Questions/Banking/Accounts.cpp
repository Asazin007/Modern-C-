#include "Accounts.hpp"

int Accounts::m_next_Accno=510860;

Accounts::Accounts(int m_acc_types_, Customer_ptr m_customer_, long int m_current_balance_)
    : m_customer(m_customer_), m_current_balance(m_current_balance_)
{
    m_Acc_no = ++m_next_Accno;
    m_card = std::make_shared<Card>();

    switch (m_acc_types_)
    {
    case 1:
        m_acc_types = AccountTypes::SAVINGS_ACCOUNT;
        break;
    case 2:
        m_acc_types = AccountTypes::CURRENT_ACCOUNT;
        break;
    case 3:
        m_acc_types = AccountTypes::SALARY_ACCOUNT;
        break;
    case 4:
        m_acc_types = AccountTypes::NRI_ACCOUNT;
        break;
    default:
        throw WrongInputException("wrong input\n");
        
    }
}

std::string Accounts::GetAccountTypeToString(const AccountTypes type) const
{
    switch (type)
    {
    case AccountTypes::SAVINGS_ACCOUNT:
        return "Savings Account";
    case AccountTypes::CURRENT_ACCOUNT:
        return "Current Account";
    case AccountTypes::SALARY_ACCOUNT:
        return "Salary Account";
    case AccountTypes::NRI_ACCOUNT:
        return "NRI Account";
    default:
        return "Unknown Account Type";
    }
}

void Accounts::WithdrawMoney(const long int &bal)
{
    if(this->m_current_balance>=bal){
        m_current_balance= m_current_balance-bal;
        m_transactions.push_back(std::make_shared<Transaction>(-1*bal));
    }
    else{
        throw LowBalanceException("Balace is Low\n");
    }
}

void Accounts::DepositMoney(const long int &bal)
{
    m_current_balance+=bal;
    m_transactions.push_back(std::make_shared<Transaction>(bal));
}

void Accounts::RollBack()
{
    if(!m_transactions.empty()){
        m_current_balance=m_current_balance +(-1*(m_transactions.back()->transaction()));
        m_transactions.pop_back();
    }
}

std::ostream &operator<<(std::ostream &os, const Accounts &rhs)
{

    os << "Account Type: " << rhs.GetAccountTypeToString(rhs.m_acc_types)<<std::endl
       << " Account No: " << rhs.m_Acc_no<<std::endl
       << " Customer Details: " << *rhs.m_customer
       << " Card: " << *rhs.m_card
       << " Current Balance: " << rhs.m_current_balance;
    return os;
}
