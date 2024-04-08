#include "ID.h"
#include <string>
ID::ID(Country country, int year, int month, Track track, int batch_number, Location location, LEVEL level)
    : m_country(country), m_year(year), m_month(month), m_track(track), m_batch_number(batch_number), m_level(level)
{}

std::string ID::country() const
{
    std::string country;
    switch (this->m_country)
    {
    case Country::IN:
        country = "IN";
        break;
    case Country::GR:
        country = "GR";
        break;
    case Country::CH:
        country = "CH";
        break;
    case Country::SK:
        country = "SK";
        break;
    case Country::JP:
        country = "JP";
        break;
    default:
        break;
    }

    return country;
}

std::string ID::track() const
{
    std::string track;

    switch (this->m_track)
    {
    case Track::CPP:
        track = "CPP";
        /* code */
        break;
    case Track::JAVA:
        track = "JAVA";
        /* code */
        break;

    case Track::PYTHON:
        track = "PYTHON";
        /* code */
        break;
    case Track::MBD:
        track = "MBD";
        /* code */
        break;

    default:
        break;
    }
    return track;
}

std::string ID::location() const
{
    std::string loc;
    switch (this->m_location)
    {
    case Location::P:
        loc = "P";
        break;
    case Location::B:
        loc = "B";
        break;
    case Location::K:
        loc = "K";
        break;

    default:
        break;
    }
    return loc;
}

std::string ID::level() const
{
    std::string level;
    switch (this->m_level)
    {
    case LEVEL::BT:
        /* code */
        level = "BT";
        break;

    case LEVEL::AT:
        /* code */
        level = "AT";
        break;

    default:
        break;
    }
    return level;
}

std::string ID::stringID() const
{
    std::string id = "";
    id += this->country();
    int year = m_year%100;
    id += std::to_string(year);

    if (this->m_month <= 9 && this->m_month > 0)
    {
        id = id + "0" + std::to_string(this->m_month);
    }
    else if (this->m_month > 9 && this->m_month <= 12)
    {
        id += std::to_string(this->m_month);
    }
    id += this->level();
    id = id + "01_";
    if (this->m_country == Country::IN)
    {
        id += this->location();
    }

    else
    {
        id += "ANY";
    }
    id += "_" + this->track() + "_Batch " + std::to_string(this->m_batch_number);
    return id;
}

std::ostream &operator<<(std::ostream &os, const ID &rhs)
{
    os << "ID: " << rhs.stringID();
    return os;
}
