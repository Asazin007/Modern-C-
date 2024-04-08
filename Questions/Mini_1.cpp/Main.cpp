#include "Functionalities.h"

int main(){
    container data;
    try
    {
        CreateObject(data);

        if (std::optional<std::vector<float>> disprices = FindDiscountPrice(data); disprices.has_value())
        {
            std::cout << "Discount Prices\n";
            for (float p : disprices.value())
            {
                std::cout << p << " ";
            }
        }

        std::cout<<"Count of tax amount: "<<FindTaxAmount(data);
        if(CheckLicensetype(data)){
            std::cout<<"\nAll license type is same";
        }
        else
            std::cout << "\nAll license type is not same";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}