#include <iostream>
#include <array>
#include <unordered_map>

int main(){

    std::unordered_map<int, std::string> map{

        std::make_pair<int, std::string>(102, "Asim"),
        std::make_pair<int, std::string>(103, "Rohan"),
        {203, "Rajnikant"},
        {204, "Yash"}
        };


    
    //structural binding
    std::array<int,2> data{123,456000}; //things which are of fixed size and strore data sequence
    auto [empId, empsal]=data;
    for(auto& [k,v]: map){
        std::cout<<"Key is: "<<k<<" value is "<<v<<'\n';
    }

}

//noexcept pdhna h

