#include<iostream>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;

double fraction;
char end;
int main()
{
    int tests;
    cin >> tests;
    
    for (int i = 0; i < tests; i++)
    {
        
        int numChildren = 0;
        cin >> numChildren;
        
        if (numChildren == 0) 
        {
            cout << "YES" << endl;
            continue;
        }

        double candySum = 0;
        for (int j = 0; j < numChildren; j++)
        {
            int trash = 0;
            cin >> trash;
            candySum += trash;
        }
        candySum = candySum / numChildren;
        if (modf(candySum, &fraction) == 0.0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
}