#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string input;
    std::getline(cin, input);


    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ':' || input[i] == ';')
        {
            // :) or ;)
            if (input[i+1] == ')') cout << i << endl;
            
            else if (input[i+1] == '-')
            {
                // :-) or ;-)
                if (input[i+2] == ')') cout << i << endl;
            }
        }
    }
    return 0;
}