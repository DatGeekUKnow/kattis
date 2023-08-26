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

    input = input.substr(input.size()-3);

    if (input == "eh?")
    {
        cout << "Canadian!" << endl;
    }
    else
    {
        cout << "Imposter!" << endl;
    }
    return 0;
}