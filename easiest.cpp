#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int sumDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int main()
{
    int num;
    while (cin >> num)
    {
        if (num == 0) break;
        // calculate sum of given digits
        int n = num;
        int sum = sumDigits(n);
        
        for (int i = 11; i < 1000000; i++)
        {
            if (sumDigits(num*i) == sum)
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}