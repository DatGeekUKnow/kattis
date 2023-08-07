#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

enum Outcome { magic, left, right, cycle };

class Frog
{
    public:
    int location; // 1's based index of frog in game array
    vector<int> memory;
    int hops = 0;

    int hopLeft(int val)
    {
        location -= abs(val);
        hops++;
        return location;
    }
    int hopRight(int val)
    {
        location += val;
        hops++;
        return location;
    }
    Frog(int loc)
    {
        location = loc;
        memory.push_back(loc);
    }
};

int main()
{
    vector<int> board;
    int len, location, magic_number;
    cin >> len >> location >> magic_number;
    Outcome result;

    Frog f(location); // convert one's based index to 0.

    int num = 0;
    for (int i = 0; i < len; i++)
    {
        cin >> num;
        board.push_back(num);
    }

    bool playing = true;
    f.memory.push_back(board[f.location-1]);
    do
    {
        cout << board[f.location-1] << endl;
        if (board[f.location-1] == magic_number)
        {
            result = magic;
            playing = false;
            break;
        }
        else if (board[f.location-1] > 0)
        {
            f.hopRight(board[f.location-1]);
            if (f.location >= board.size())
            {
                result = right;
                playing = false;
                break;
            }
            f.memory.push_back(board[f.location-1]);
        }
        else if (board[f.location-1] < 0)
        {
            f.hopLeft(board[f.location-1]);
            if (f.location < 0)
            {
                result = left;
                playing = false;
                break;
            }
            f.memory.push_back(board[f.location-1]);
        }
        if (std::find(f.memory.begin(), f.memory.end(), board[f.location-1]) != f.memory.end())
        {
            result = cycle;
            playing = false;
            break;            
        }
    } while (playing);
    
    switch(result)
    {
        case magic:
            cout << "magic";
            break;
        case cycle:
            cout << "cycle";
            break;
        case right:
            cout << "right";
            break;
        case left:
            cout << "left";
            break;
    }
    cout << endl << f.hops;


    return 0;
}