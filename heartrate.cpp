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
    
    cout.precision(4);
    cout << std::fixed;
    for (int i = 0; i < numCases; i++)
    {
        cin >> beats >> seconds;
        double bpm = (beats / seconds) * 60;

        double variance = 60/seconds;
        
        double abpm = bpm - variance;
        double max_bpm = bpm + variance;
        cout << abpm;
        cout << " " << bpm << " " << max_bpm << endl;

    }

    return 0;
}