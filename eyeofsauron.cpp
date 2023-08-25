#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    bool left = true;
    bool right = false;

    int lcounter = 0;
    int rcounter = 0;

    char eval;

    while (cin >> eval)
    {
        if (eval == '|' && left)
        {
            lcounter++;
        }
        else if (eval == '|' && right)
        {
            rcounter++;
        }
        else if (eval == '(')
        {
            left = false;
        }
        else if (eval == ')')
        {
            right = true;
        }
    }

    (lcounter == rcounter) ? cout << "correct" << endl : cout << "fix" << endl;

    return 0;
}