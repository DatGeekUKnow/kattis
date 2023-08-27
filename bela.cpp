#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    int numHands;
    char domSuit;
    cin >> numHands;
    cin >> domSuit;
    string card;
    int sum = 0;
    for (int i = 0; i < numHands; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> card;
            switch (card[0])
            {
                case 'A':
                    sum += 11;
                    break;
                case 'K':
                    sum += 4;
                    break;
                case 'Q':
                    sum += 3;
                    break;
                case 'J':
                    if (card[1] == domSuit) sum += 20;
                    else sum += 2;
                    break;
                case 'T':
                    sum += 10;
                    break;
                case '9':
                    if (card[1] == domSuit) sum += 14;
                    break;
                default:
                    break;
            }
        }
    }
    cout << sum << endl;

    return 0;
}