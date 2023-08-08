#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int length; // number of test cases
    int numScores; // number of scores in a test case
    int numOverAvg = 0;
    float avg;
    vector<int> scores;

    cout.setf(std::ios::fixed, std::ios::floatfield);
    cout.precision(3);
    cin >> length;

    for (int i = 0; i < length; i++)
    {
        avg = 0;
        numOverAvg = 0;
        cin >> numScores;
        scores.resize(numScores);
        for (int j = 0; j < numScores; j++)
        {
            cin >> scores[j];
            avg += scores[j];
        }
        avg = avg / numScores;
        for (int j = 0; j < scores.size(); j++)
        {
            if (scores[j] > avg) numOverAvg++;
        }
        cout << 100*((float)numOverAvg/numScores) << '%' << endl;
    }
    return 0;
}