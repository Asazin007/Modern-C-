/*
const keywords
Rule 1: const is applied to thr token on its immediate left.
if there is nothing on the left of the const , appy const on the token to its right

Rule 2:pointer symbol * is considered a seperate token
*/
class dummy
{
private:
    int id;
    float salary;

public:
    dummy(int i, float f) : id(i), salary(f) {}
    ~dummy() = default;
    void setsal(float &f)
    {
        salary = f;
    }
    float getsalary() const
    {
        return salary;
    }
};

#include <iostream>
int main()
{
    // scenario 1:
    const int n1 = 10;
    int const n2 = 20;
    // scenrio 2:
    int n3 = 99;
    int n4 = 188;
    // 2a
    const int *ptr = &n3; // here only data is constant not address
    ptr = &n4;
    // 2b

    int *const ptr2 = &n3; // here only address is const not data
    *ptr2 = 100;

    const int *const ptr3 = &n4; // both is const
    const dummy d1 = {101, 65949.00f};
    std::cout << d1.getsalary();
}
