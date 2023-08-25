#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int gcvwr, truck, numItems;
    cin >> gcvwr >> truck >> numItems;

    // gcvwr - weight of truck * 0.9 gives usable weight
    int usable = (gcvwr - truck) * 0.9;

    int tmpWeight;
    for (int i = 0; i < numItems; i++)
    {
        cin >> tmpWeight;
        usable -= tmpWeight;
    }
    cout << usable << endl;

    return 0;
}