#include "Operations.h"
#include <string>
#include <cstring>
#include <climits>
op_ptr Operations::m_soloObj{nullptr};

op_ptr Operations::getObj()
{
    if (m_soloObj)
        return m_soloObj;
    else
    {
        m_soloObj.reset(new Operations());
        return m_soloObj;
    }
}

void Operations::CreateObjects()
{
    m_drivers.push_back(std::make_shared<Driver>(
        "1001",
        DriverRating::STAR_2));
    m_drivers.push_back(std::make_shared<Driver>(
        "1002",
        DriverRating::STAR_3));
    m_drivers.push_back(std::make_shared<Driver>(
        "1003",
        DriverRating::STAR_1));

    m_data.emplace("111", std::make_shared<CabRide>(
                              Vtype_id{111},
                              RideType::LOCAL,
                              PaymentMode::CARD,
                              2300,
                              "Pune",
                              "Mumbai",
                              *(m_drivers[0])));
    m_data.emplace("112", std::make_shared<CabRide>(
                              Vtype_id{"112"},
                              RideType::OUTSTATION,
                              PaymentMode::UPI,
                              2300,
                              "Pune",
                              "Lucknow",
                              *(m_drivers[1])));
    m_data.emplace("113", std::make_shared<CabRide>(
                              Vtype_id{113},
                              RideType::RENT,
                              PaymentMode::WALLET,
                              3230,
                              "Hinjewadi",
                              "Lucknow",
                              *(m_drivers[2])));
}

PaymentMode Operations::PaymentmodeID(Vtype_id &id)
{
    std::string s;
    PaymentMode m;
    if (m_data.empty())
        throw Exception(std::future_errc::no_state, "Data is empty\n");

    if (std::holds_alternative<int>(id))
    {
        s = std::to_string(std::get<1>(id));
    }
    else
        s = std::get<0>(id);

    auto itr = std::find_if(m_data.begin(), m_data.end(), [&s](const std::pair<std::string, CarRide_ptr> &mp)
                            {
                if(std::holds_alternative<int>( mp.second->id())){
                    return s == std::to_string(std::get<1>(mp.second->id()));
                }
                else{
                    return s== std::get<0>(mp.second->id());
                } });

    if (itr == m_data.end())
        throw Exception(std::future_errc::no_state, "No found\n");
    m= (*itr).second->paymentmode();
    return m;
}

std::array<RideType, 2> Operations::MAXMINRideType()
{
    if (m_data.empty())
        throw Exception(std::future_errc::no_state, "Data is empty\n");
    std::array<RideType, 2> type;
    RideType mx, mn;
    auto max = std::max_element(m_data.begin(), m_data.end(), [](const std::pair<std::string, CarRide_ptr> &mp1, const std::pair<std::string, CarRide_ptr> &mp2)
                                { return mp1.second->fare() < mp2.second->fare(); });
    auto min = std::min_element(m_data.begin(), m_data.end(), [](const std::pair<std::string, CarRide_ptr> &mp1, const std::pair<std::string, CarRide_ptr> &mp2)
                                { return mp1.second->fare() < mp2.second->fare(); });

    mx =(*max).second->ridetype();
    mn=(*min).second->ridetype();
    type[0] = mx;
    type[1] = mn;
    return type;
}

std::vector<std::string> Operations::PickofN(const int &n)
{
    std::vector<std::string> pic;
    if (m_data.empty())
        throw Exception(std::future_errc::no_state, "Data is empty\n");
    if (n <= 0 || n > m_data.size())
        throw Exception(std::future_errc::no_state, "Invalid N\n");

    for (auto ptr : m_data)
    {
        pic.push_back(ptr.second->pickupLoc());
    }
    return pic;
}

DriverCon Operations::NDrivers(const int &n)
{

    if (m_drivers.empty())
        throw Exception(std::future_errc::no_state, "Data is empty\n");
    if (n <= 0 || n > m_drivers.size())
        throw Exception(std::future_errc::no_state, "Invalid N\n");

    DriverCon firstn;
    for (int i = 0; i < n; i++)
    {
        firstn.push_back(m_drivers[i]);
    }
    return firstn;
}
