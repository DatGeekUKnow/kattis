#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int sides, hcut, vcut;
    cin >> sides >> hcut >> vcut;

    int vol=0;
    if (sides-hcut > hcut)
    {
        if (sides-vcut > vcut)
        {
            vol = (sides-hcut) * (sides - vcut) * 4;
        }
        else
        {
            vol = (sides - hcut) * vcut * 4;
        }
    }
    else
    {
        if (sides - vcut > vcut)
        {
            vol = hcut * (sides - vcut) * 4;
        }
        else
        {
            vol = hcut * vcut * 4;
        }
    }
    cout << vol << endl;
}