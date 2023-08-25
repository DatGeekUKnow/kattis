#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int beats;
    double seconds;
    int numCases;

    cin >> numCases;
    
    cout.precision(5);
    cout << std::fixed;
    for (int i = 0; i < numCases; i++)
    {
        cin >> beats >> seconds;
        double ratio = (beats / seconds);
        double bpm = ratio * 60;
        double abpm = bpm / ratio;
        cout << abpm;
        cout << " " << bpm << endl;

    }

    return 0;
}