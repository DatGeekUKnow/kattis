#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string inp;
    cin >> inp;
    for (int i = 0; i < inp.size()-2; i++)
    {
        if (inp[i] == inp[i+2]) 
        {
            cout << "0" << endl;
            return 0;
        }
    }
    
    cout << "1" << endl;
    
    test("robust");
    test("icpc");
}



int test()
{
    string input;
    cin >> input;
    bool isDupe = false;
    for(int i = 0; i < input.size(); ++i)
    {
        if (std::find(input.begin(), input.end(), input[i]) != input.end())
        {
            isDupe = true;
        }
    }

    cout << ((isDupe || input.size() < 2)? "1" : "0") << endl;

    return 0;
}