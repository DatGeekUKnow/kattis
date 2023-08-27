#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int numCases;
    cin >> numCases;

    string battle;
    int won = 0;
    for (int i = 0; i < numCases; i++)
    {
        cin >> battle;
        if (battle.find("CD") == string::npos)
        {
            won++;
        }
    }
    cout << won << endl;
    return 0;
}