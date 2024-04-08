#ifndef LICENSE_H
#define LICENSE_H
#include "LicenseType.h"
#include<iostream>
class License{
private:
    int m_license_no;
    static int counter;
    LicenseType m_license_type;

public: 
    License() = delete;
    License(const License &) = delete; // disabled copy constructor
    License(License &&) = delete; // disabled move constructor brand new in C++11
    License &operator=(const License &) = delete; // disabled assignment operator
    License &operator=(License &&) = delete;	  // disabled assignment move operator brand new in C++11
    License(LicenseType type);
    ~License() = default;

    int licenseNo() const { return m_license_no; }

    LicenseType licenseType() const { return m_license_type; }
    void setLicenseType(const LicenseType &license_type) { m_license_type = license_type; }

    friend std::ostream &operator<<(std::ostream &os, const License &rhs);
};

#endif // LICENSE_H
