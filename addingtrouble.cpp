#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    if (a+b == c) cout << "correct!" << endl;
    else cout << "wrong!" << endl;
}