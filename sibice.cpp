#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int numMatches;
    double len, wid;
    cin >> numMatches >> len >> wid;

    double diag = std::sqrt((len*len)+(wid*wid));
    int match;
    for (int i = 0; i < numMatches; i++)
    {
        cin >> match;
        if (match <= diag)
        {
            cout << "DA" << endl;
        }
        else
        {
            cout << "NE" << endl;
        }
    }
    return 0;
}