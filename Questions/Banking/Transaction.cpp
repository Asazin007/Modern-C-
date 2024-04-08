#include "Transaction.hpp"

Transaction::Transaction(long int transac)
:m_transaction(transac)
{
}

std::ostream &operator<<(std::ostream &os, const Transaction &rhs)
{
    os << "m_transaction: " << rhs.m_transaction;
    return os;
}
