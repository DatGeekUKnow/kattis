#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::pair;

int main ()
{
    int num; // number of units
    string unit, unit2;
    map<string, pair<string, double>> values;
    while (cin >> num)
    {
        values = {};
        for (int i = 0; i < num; i++)
        {
            cin >> unit;
            values[unit] = {};
        }

        int val;
        char trash;
        for (int i = 1; i < num; i++)
        {
            cin >> unit;
            cin >> trash;
            cin >> val;
            cin >> unit2;
            values[unit] = {unit2, val};
        }

        for (auto& i : values)
        {
            cout << i.first << endl;
        }
    }
    return 0;
}