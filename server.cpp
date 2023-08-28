#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int numCases, timeLimit;
    cin >> numCases >> timeLimit;

    int len, sum = 0;
    int passed = 0;
    for (int i = 0; i < numCases; i++)
    {   //read in length of each task
        cin >> len;
        sum += len;
        if (sum <= timeLimit) passed++;
    }
    cout << passed << endl;
    return 0;
}