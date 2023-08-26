#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int wc, hc, ws, hs;
    cin >> wc >> hc >> ws >> hs;

    if (ws <= (wc - 2) && (hs <= (hc - 2)))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}