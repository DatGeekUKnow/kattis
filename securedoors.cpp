#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int loglen;
    cin >> loglen;
    vector<string> itb;

    bool anomaly;
    string word;
    for (int i = 0; i < loglen; i++)
    {
        anomaly = false;

        cin >> word;
        if (word == "entry")
        {
            cin >> word; // who entered
            cout << word << " entered";
            if (std::find(itb.begin(), itb.end(), word) == itb.end())
            {
                // if not found in the building, add them.
                itb.push_back(word);
            }
            else anomaly = true;

        }
        else if (word == "exit")
        {
            cin >> word; // who exited
            cout << word << " exited";
            if (std::find(itb.begin(), itb.end(), word) == itb.end())
            {
                // if they aren't found in the building, this is an anomaly.
                anomaly = true;
            }
            else
            {
                itb.erase(std::find(itb.begin(), itb.end(), word));
            }

        }
        if (anomaly)
        {
            cout << " (ANOMALY)" << endl;
        }
        else cout << endl;
    }
    return 0;
}