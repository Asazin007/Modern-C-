#include "Functionalities.h"

void CreateObject(container &data)
{
    data.push_back(std::make_shared<Device>(
        "1234r",
        "poco",
        20000.0f,
        1.5f,
        Type::ACCESSORY,
        std::make_shared<License>(LicenseType::OWNED),
        std::make_shared<Owner>("Asim")));

    data.push_back(std::make_shared<Device>(
        "1235r",
        "apple",
        200000.0f,
        2.0f,
        Type::MOBILE,
        std::make_shared<License>(LicenseType::OWNED),
        std::make_shared<Owner>("Yuvraj")));

    data.push_back(std::make_shared<Device>(
        "1238r",
        "watch",
        20000.0f,
        1.9f,
        Type::ACCESSORY,
        std::make_shared<License>(LicenseType::RENTED),
        std::make_shared<Owner>("Satyam")));

    data.push_back(std::make_shared<Device>(
        "1234f",
        "computer",
        20000.0f,
        1.2f,
        Type::WORKSTATION,
        std::make_shared<License>(LicenseType::OWNED),
        std::make_shared<Owner>("Gourav")));
}

std::optional<std::vector<float>> FindDiscountPrice(container &data)
{
    // int i=0;
    if (data.empty())
        throw EmptyContainerException("Container is Emoty\n");

    // float temp = 0.0f;
    std::vector<float> discountprice;
    for (Device_ptr ptr : data)
    {
        if (ptr->type() == Type::MOBILE || ptr->type() == Type::WORKSTATION)
        {

            discountprice.push_back(ptr->price() * 0.02f);
        }
        else if (ptr->type() == Type::ACCESSORY)
        {

            discountprice.push_back(ptr->price() * 0.05f);
        }
    }
    if(discountprice.empty())
    return std::nullopt;
    return discountprice;
}

int FindTaxAmount(container &data)
{
    if (data.empty())
        throw EmptyContainerException("COntainer is Emoty\n");

    int count = 0;
    for (Device_ptr ptr : data)
    {
        if (ptr->sarValue() >= 1.0f && ptr->sarValue() <= 1.5f && ptr->license()->licenseType() == LicenseType::OWNED)
            count++;
        if (ptr->sarValue() >= 1.5f && ptr->sarValue() <= 2.0f && ptr->license()->licenseType() == LicenseType::RENTED)
            count++;
    }
    return count;
}

bool CheckLicensetype(container &data)
{
    if (data.empty())
        throw EmptyContainerException("COntainer is Emoty\n");
    Device_ptr f = data[0];

    for (int i = 1; i < data.size(); i++)
    {
        if (data[i]->license()->licenseType() != f->license()->licenseType())
        {
            return false;
        }
    }
    return true;
}
