#include<iostream>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    long tests;
    cin >> tests;
    
    for (int i = 0; i < tests; i++)
    {
        
        long numChildren = 0;
        cin >> numChildren;

        long candySum = 0;
        for (int j = 0; j < numChildren; j++)
        {
            long trash = 0;
            cin >> trash;
            candySum += trash % numChildren;
        }

        if (numChildren == 0 || candySum % numChildren  ==  0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
}