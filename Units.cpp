#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

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
    vector<string> keys;
    vector<vector<double>> values;
    while (cin >> num)
    {
        if (num == 0) return 0;
        values = {};
        keys = {};
        values.resize(num);
        for(auto& vect : values)
        {
            vect.resize(num);
        }

        // Initialize keys
        for (int i = 0; i < num; i++)
        {
            cin >> unit;
            keys.push_back(unit);
            values[i][i] = 1;
        }

        double val;
        char trash;
        for (int i = 1; i < num; i++)
        {
            val = 0.0;
            cin >> unit;
            cin >> trash; // throw away = sign
            cin >> val;
            cin >> unit2;
            auto unitIndex = std::find(keys.begin(), keys.end(), unit);
            auto unit2Index = std::find(keys.begin(), keys.end(), unit2);
            values[unitIndex - keys.begin()][unit2Index - keys.begin()] = val;
            values[unit2Index - keys.begin()][unitIndex - keys.begin()] = 1.0/val;
        }

        for (int x = 0; x < keys.size(); ++x) 
        {
            for(int y = 0; y < keys.size(); ++y) 
            {
                for(int z = 0; z < keys.size(); ++z)
                {
                    if (values[z][y] == 0 && values[z][x] != 0)
                    {
                        values[z][y] = values[x][y] * values[z][x];
                    }
                }
            }
        }

        cout << std::setprecision(11);        
        for (auto& vec : values)
        {
            auto val = std::find_if(vec.begin(), vec.end(), [](double val) { return val < 1;});
            if (val == vec.end()) 
            { // this is our prize vector
                // print in descending order
                // match key index to keys vector
                vector<double> newVals;
                std::copy(vec.begin(), vec.end(), std::back_inserter(newVals));
                std::sort(newVals.begin(), newVals.end());
                
                for(int i = 0; i < newVals.size(); ++i)
                {
                    auto itr = std::find(vec.begin(), vec.end(), newVals[i]);
                    int index = itr - vec.begin();
                    cout << vec[index] << keys[index];
                    if (i < newVals.size() - 1) {
                        cout << " = ";
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}