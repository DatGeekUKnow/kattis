//  08/02/2023 Pair Programming with Gavin McCulley
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::reverse;

//  "Reversed Binary Numbers" https://open.kattis.com/problems/reversebinary

string decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];
    stringstream result;

    // counter for binary array
    int i = 0;
    while (n > 0)
    {
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        result << binaryNum[j];

    return result.str();
}

int main()
{
    int num;
    cin >> num;

    string binary = decToBinary(num); 
    reverse(binary.begin(), binary.end()); 
    cout << stoi(binary, 0, 2);
    return 0;
}