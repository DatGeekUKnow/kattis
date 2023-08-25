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
    while (cin >> temp)
    {
        words.push_back(temp);
    }

    for (int i = 0; i < words.size(); ++i)
    {
        auto iter = std::find(words.begin(), words.end(), words[i]);
        if (iter != words.end() && iter - words.begin() != i) cout << "yes" << endl;
        return 0;
    }

    cout << "no" << endl;
}