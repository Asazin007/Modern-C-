#include "Operations.h"

int main(){

    op_ptr obj = Operations::getObj();

    try
    {
        std::future<void> co=std::async(&Operations::CreateObjects,obj.get());
        co.wait();
        Vtype_id tid{111};
         std::future<PaymentMode> pm = std::async(&Operations::PaymentmodeID, obj, std::ref(tid));
         PaymentMode p =pm.get();
         std::string s;
         if (p == PaymentMode::CASH)
             s = "Cash";
         if (p == PaymentMode::CARD)
             s = "CARD";
         if (p == PaymentMode::UPI)
             s = "UPI";
         std::cout<<"Paymentmode is "<<s<<'\n';
         std::future<std::array<RideType, 2>> arr = std::async(&Operations::MAXMINRideType, obj);
         if (std::array<RideType, 2> temp = arr.get(); !temp.empty()){
            std::cout<<"Array of car ride type in not empty\n";
         }
         std::future<std::vector<std::string>> npic = std::async(&Operations::PickofN, obj,2);
         if (std::vector<std::string> tem=npic.get() ; !tem.empty()){
            for(auto i :tem){
                std::cout<<i<<" ";
            }
         }
         std::future<DriverCon> ndri = std::async(&Operations::NDrivers, obj, 2);
         if (DriverCon tem= ndri.get(); !tem.empty())
         {
             for (auto i : tem)
             {
                 std::cout << *i << " ";
             }
         }
        }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}