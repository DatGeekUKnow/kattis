#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> toLearn;
    int numKnots;
    cin >> numKnots;

    int tmp;
    for (int i = 0; i < numKnots; i++)
    {
        cin >> tmp;
        toLearn.push_back(tmp);
    }
    for (int i = 0; i < numKnots-1; i++)
    {
        cin >> tmp;
        toLearn.erase(std::remove_if(toLearn.begin(), toLearn.end(), 
                       [tmp](int i) { return i == tmp; }), toLearn.end());
    }

    cout << toLearn[0] << endl;
    return 0;
}