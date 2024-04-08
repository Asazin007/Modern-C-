#include <iostream>
#include<memory>
class Example1
{
private:
    /* data */
    std::string m_name;
    int m_id;
public:
    Example1(int id, std::string name) :m_id(id), m_name(name) {}
    ~Example1() {}
};

void dummy(){
    
    // std::shared_ptr<Example1> sptr{new Example1(10, "Asim")};
    std::shared_ptr<Example1> spt{std::make_shared<Example1>(10,"Asim")};
    int n1{0};

    std::cin>>n1;
    std::cout<<10/n1;
    // delete ex1;
}
int main(){
    try
    {dummy();}
    catch(std::exception& ex){
        
    }


}