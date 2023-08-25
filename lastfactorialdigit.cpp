#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int numCases;
    cin >> numCases;

    int val;
    for (int i = 0; i < numCases; i++)
    {
        cin >> val;
        for (int j = val-1; j > 0; j--)
        {
            val *= j;
        }
        std::ostringstream os;
        os << val;
        std::string result = os.str();
        cout << result.back() << endl;
    }


    return 0;
}