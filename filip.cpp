#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string num1, num2;
    cin >> num1 >> num2;

    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    if (std::stoi(num1) > std::stoi(num2))
    {
        cout << num1;
    }
    else
    {
        cout << num2;
    }
    cout << endl;

    return 0;
}