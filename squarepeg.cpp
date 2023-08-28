#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int len, rad;
    cin >> len >> rad;

    if (len*std::sqrt(2) <= rad*2)
    {
        cout << "fits" << endl;
    }
    else
    {
        cout << "nope" << endl;
    }

    return 0;
}