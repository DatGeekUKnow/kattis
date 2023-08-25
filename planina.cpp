#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int numSides = 1;
    int iter = 0;

    cin >> iter;

    for (int i = 0; i < iter; i++)
    {
        numSides *= 2;
    }
    numSides++;
    cout << numSides*numSides;
}