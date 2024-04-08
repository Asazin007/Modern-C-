#include <iostream>
class Parent
{
private:
    /* data */
public:
 Parent(/* args */) {}
    ~Parent() {}
     virtual void magic()=0; 
};
class Child: public Parent
{
private:
    /* data */
public:
    Child(/* args */) {}
    virtual ~Child() {}
    void magic( ) override{ std::cout<<"magic of child\n"; }
    void ChildDisplay(){ std::cout<< "Done! \n"; }
};



int main(){
    float f1 =10.34f;
    int n1 =static_cast<int>(f1);               //int n1 =(float) f1; its c style cast


    std::cout<<n1<<std::endl;//lossy conversion

    //runtime polymorphism is in picture
    Parent* ptr= new Child(); //upcast
    ptr->magic();
    //ptr->ChildDisplay(); not works
// in dynamic cast atleast one function should be virtual
    Child* temp =dynamic_cast<Child*>(ptr); //downcast
    try
    {
        /* code */
        Child &temp2 = dynamic_cast<Child &>(*ptr);
        temp2.ChildDisplay();
    }
    catch(const std::bad_cast& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    if(temp!=nullptr)
    temp->ChildDisplay();

 


}