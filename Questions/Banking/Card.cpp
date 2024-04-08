#include "Card.hpp"

int Card::m_gen=1;

Card::Card()
{
    m_cardno = 1945123 + m_gen++;
    m_cvv = 243 + m_gen++;

    m_date = std::make_shared<Date>(4, 2030);
}

Card::Card(std::shared_ptr<Date> m_date_)
    : m_date(m_date_)
{
    m_cardno= 12345453 + m_gen;
    m_cvv=243+m_gen++;
  

}
std::ostream &operator<<(std::ostream &os, const Card &rhs) {
    os << "m_cardno: " << rhs.m_cardno
       << " m_cvv: " << rhs.m_cvv
       << " m_date: " << *rhs.m_date;
    return os;
}
