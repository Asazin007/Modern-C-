#ifndef ID_H
#define ID_H

#include <iostream>
#include "Country.h"
#include "Track.h"
#include "LEVEL.h"
#include "Location.h"

class ID
{
private:
    Country m_country;
    int m_year;
    int m_month;
    Track m_track;
    int m_batch_number;
    Location m_location;
    LEVEL m_level;
    
public:
    ID() = delete;
    ID(const ID&) = delete;
    ID(const ID&&) = delete;
    ID operator = (const ID&) = delete;
    ID operator = (const ID&&) = delete;
    ID(Country country, int year, int month, Track track, int batch_number, Location location, LEVEL level);
    ~ID() = default;

    std::string country() const ;

    std::string track() const;

    std::string location() const;

    std::string level() const;

    int year() const { return m_year; }
    void setYear(int year) { m_year = year; }

    int month() const { return m_month; }
    void setMonth(int month) { m_month = month; }

    int batchNumber() const { return m_batch_number; }
    void setBatchNumber(int batch_number) { m_batch_number = batch_number; }


    std::string stringID() const;

    friend std::ostream &operator<<(std::ostream &os, const ID &rhs);
    

    
};

#endif // ID_H
