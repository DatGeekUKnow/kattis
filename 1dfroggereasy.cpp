#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

int board_squares, frogloc, magic_number;
enum outcome { magic, left, right, cycle };
int numHops = 0;
outcome result;
bool playing;

int main ()
{
    // read in start conditions
    cin >> board_squares >> frogloc >> magic_number;
    
    // read in all square indexes
    vector<int> board;
    int abc;
    for (int i = 0; i < board_squares; i++)
    {
        cin >> abc;
        board.push_back(abc);
    }
    playing = true;
    
    int hops = 0;
    vector<int> memory;
    while(playing)
    {
        //cout << board[frogloc-1] << std::endl;
        if (frogloc < 1)
        {
            result = left;
            playing = false;
            break;
        }
        
        // check if the magic number is on the start square
        if (magic_number == board[frogloc-1])
        {
            result = magic;
            playing = false;
            break;
        }
        if (board[frogloc-1] >= 1)
        {
            //positive
            frogloc += board[frogloc-1];
            hops++;
            if (frogloc > board_squares)
            {
                result = right;
                playing = false;
                break;
            }
        }
        else
        {
            //negative
            frogloc -= abs(board[frogloc-1]);
            hops++;
            if (frogloc < 0)
            {
                result = left;
                playing = false;
                break;
            }
        }
        
        if (std::find(memory.begin(), memory.end(), board[frogloc-1]) != memory.end())
        {
            result = cycle;
            playing = false;
            break;
        }
        else
        {
            memory.push_back(board[frogloc-1]);
        }
    }
    
    switch(result)
    {
        case magic:
            cout << "magic";
            break;
        case cycle:
            cout << "cycle";
            break;
        case left:
            cout << "left";
            break;
        case right:
            cout << "right";
            break;
    }
    cout << std::endl << hops << std::endl;
    //debug
    //for (int i = 0; i < board_squares; i++)
    //{
    //    cout << board[i] << ' ';
    //}
}