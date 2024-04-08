
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
        {
            return false;
        }

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    string isSumOfTwo(int n)
    {
        for (int i = 2; i <= n / 2; ++i)
        {
            if (isPrime(i) && isPrime(n - i))
            {
                
                return "Yes";
            }
        }
        return "No";
    }

   
};
int main()
{
    int N;
    cout << "Enter the number N: ";
    cin >> N;
Solution s;

cout << s.isSumOfTwo(N) << endl;

return 0;
}