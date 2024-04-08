#include<functional>
#include <iostream>

class simple
{
private:
    /* data */
    int n{89};
public:
    simple(/* args */) {}
    void operator()(int n){
        std::cout<<n<<"\n";
    }
    ~simple() {}

    int getN() const { return n; }
    void setN(int n_) { n = n_; }
};
void add(int n1,int n2){
    std::cout<<n1+n2;
}
void Adaptor(std::function<void(int)> fn,int n){
    fn(n);
}
int main(){

    std::function<void(int, int)> sr = std::function<void(int, int)>(add);

    auto fn = std::reference_wrapper<std::function<void(int, int)>>(sr);
    // fn(12,34);
    fn.get()(45,78);
    std::cout<<'\n';
    auto fnl = [](int n1, int n2)
    {
        std::cout << n1 + n2;
    };
    std::function<void(int,int)> fn = fnl;
    std::reference_wrapper < std::function<void(int,int)> > ref = fn;

     // auto lfn = std::ref(fnl);
     // lfn(23, 45);

     int a = 10;
     std::reference_wrapper<int> reff = a;
                                 
    std::reference_wrapper<simple>obj(s);
    std::cout<<obj.get().getN();
    // Adaptor(simple(),5);

}