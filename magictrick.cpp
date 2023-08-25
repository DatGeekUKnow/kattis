#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string input = "";
    cin >> input;
    string seen = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (std::find(seen.begin(), seen.end(), input[i]) != seen.end())
        {
            cout << 0 << endl;
            return 0;
        }
        else
        {
            seen += input[i];
        }
    }

    cout << 1 << endl;
    return 0;
}