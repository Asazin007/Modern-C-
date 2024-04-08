#include "CabRide.h"

CabRide::CabRide(Vtype_id id, RideType rtype, PaymentMode mode, float fare, std::string drop, std::string pickup, Driver_ref ref)
:m_id{id},m_ridetype{rtype},m_paymentmode{mode}, m_fare{fare},m_drop_loc{drop},m_pickup_loc{pickup},m_cab_driver{ref}
{
}

std::ostream &operator<<(std::ostream &os, const CabRide &rhs) {

    if (std::holds_alternative<int>(rhs.m_id)){
        os << std::get<0>(rhs.m_id);
    }
    else{
        os << std::get<1>(rhs.m_id);
    }

    os << "\n m_ridetype: " << rhs.stringride()
       << "\n m_paymentmode: " << rhs.stringmode()
       << "\n m_fare: " << rhs.m_fare
       << "\n m_drop_loc: " << rhs.m_drop_loc
       << "\n m_pickup_loc: " << rhs.m_pickup_loc
       << "\n m_cab_driver: " << rhs.m_cab_driver;
    return os;
}
