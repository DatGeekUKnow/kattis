#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string eval;
    int sum = 0;
    while(std::getline(cin, eval, ';'))
    {
        eval.erase(std::remove(eval.begin(), eval.end(), '\n'), eval.cend());
        if (std::find(eval.begin(), eval.end(), '-') != eval.end())
        {
            string num1, num2;
            bool op = false;
            for (auto& c : eval)
            {
                if (c == '-') 
                {
                    op = true;
                    continue;
                }
                if (!op) num1 += c;
                else num2 += c;
            }
            sum += (std::stoi(num2) - std::stoi(num1)) + 1;
        }
        else
        {
            sum++;
        }
    }
    cout << sum << endl;
    
}