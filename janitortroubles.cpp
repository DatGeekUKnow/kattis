#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

// max area of quadrilateral Brahmagupta's formula
double maxArea(double a, double b, double c, double d)
{
    double semiperimeter = (a + b + c + d) / 2;

    return std::sqrt((semiperimeter - a) *
                     (semiperimeter - b) *
                     (semiperimeter - c) *
                     (semiperimeter - d));
}

int main()
{
    double a,b,c,d;
    cin >> a >> b >> c >> d;

    cout.precision(16);
    cout << maxArea(a,b,c,d) << endl;

    return 0;
}