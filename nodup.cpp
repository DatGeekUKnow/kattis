#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string temp;
    vector<string> words;
    bool isDupe = false;
    while (cin >> temp)
    {
        if (std::find(words.begin(), words.end(), temp) != words.end())
        {
            isDupe = true;
        }
        words.push_back(temp);
    }

    cout << (isDupe? "no" : "yes") << endl;
}