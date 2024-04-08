#include "Functionalities.hpp"
container accounts;
void CreateAccount()
{
    int type;
    std::string name, pancard, city,country,state;
    unsigned int pincode;
    unsigned long int phone;

    std::cout<<"Select Account types"<<std::endl;
std::cout <<"1.Savings Account\n"
<<"2.Current Account\n"<<"3.Salary Account\n"<<"4.NRI Account\n";
std::cin>>type;
if(type>4||type<1)
throw WrongInputException("Wrong input");

std::cout<<"Enter Name: ";
std::cin>>name;

std::cout<<"Enter Pan Card: ";
std::cin>>pancard;

std::cout<<"Enter phone no: ";
std::cin>>phone;

std::cout << "Enter City: ";
std::cin>>city;

std::cout << "Enter state: ";
std::cin>>state;

std::cout << "Enter country: ";
std::cin>>country;

std::cout<<"Enter pincode: ";
std::cin>>pincode;

accounts.push_back(std::make_shared<Accounts>(type,
std::make_shared<Customer>(name,
 pancard,
 phone,
 std::make_shared<Address>(city,state,country,pincode)),
 0
 ));

 std::cout<<"Congrats your Account is created\n";
 std::cout<<"Your Account No is: "<<accounts.back()->accNo();
std::cout<<"\nDo you want to enter money?[1(yes)/0(no)]\n";
int i;
std::cin>>i;
if(i){
    long int money;
    std::cout<<"Enter money: ";
    std::cin>>money;
accounts.back()->DepositMoney(money);
}

std::cout << "Current Balance: " << accounts.back()->currentBalance();
}

void CheckBalance()
{
    long int acc;
std::cout<<"Enter Acc no";
std::cin>>acc;

if(accounts.empty())
throw NoTransactionException("No account yet\n");

bool found=false;
for(Account_ptr ac:accounts){
    if(acc==ac->accNo()){
        found=true;
        std::cout<<"Current Balance: "<<ac->currentBalance();
        break;
    }

}
if(!found){
    std::cerr<<"Not correct acc no\n";
}

}

Account_ptr getaccount()
{
    long int acc;
    std::cout << "\nEnter Acc no: ";
    std::cin >> acc;

    if (accounts.empty())
        throw NoTransactionException("No account yet\n");

    bool found = false;
    for (Account_ptr ac : accounts)
    {
        if (acc == ac->accNo())
        {
            found = true;
           return ac;
            break;
        }
    }
    if (!found)
    {
            throw NoTransactionException("No account found\n");
    }
    return accounts.front();
}

void Withdraw()
{
    long int bal;

        Account_ptr acc = getaccount();
        std::cout<<"\nEnter Ammount to be withdrawn: ";
        std::cin>>bal;
    acc->WithdrawMoney(bal);
    std::cout<<"Current Balance: "<<acc->currentBalance();

}

void Deposit()
{
    long int bal;

    Account_ptr acc = getaccount();
    std::cout << "\nEnter Ammount to be Deposited: ";
    std::cin >> bal;
    acc->DepositMoney(bal);
    std::cout << "Current Balance: " << acc->currentBalance();
}

void RollBack()
{
    Account_ptr acc = getaccount();
    std::cout << "\nDo you want to roll back previous transaction?[1(yes)/0(no)]\n";
    int i;
    std::cin >> i;
    if (i)
    {
        acc->RollBack();
        std::cout << "Current Balance: " << acc->currentBalance();}
        
    }
