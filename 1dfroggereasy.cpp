//  08/22/2023 Pair Programming with Gavin McCulley
// https://open.kattis.com/problems/1dfroggereasy
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
    // check if the magic number is on the start square
    while(playing)
    {
        // End cases
        // frog is on magic number
        // Magic
        if (magic_number == board[frogloc-1])
        {
            result = magic;
            playing = false;
            break;
        }

        // frog falls off left
        // Left
        // Frog falls off left
        if (frogloc < 1)
        {
            result = left;
            playing = false;
            break;
        }

        // frog falls off right
        // Right
        // Frog falls off right side
        if (frogloc > board_squares)
        {
            result = right;
            playing = false;
            break;
        }
        
        // frog has been here before 
        // Cycle
        // else add to memory
        if (std::find(memory.begin(), memory.end(), frogloc-1) != memory.end())
        {
            result = cycle;
            playing = false;
            break;
        }
        else
        {
            memory.push_back(frogloc-1);
        }


        // Move frog right if on positive number
        if (board[frogloc-1] >= 1)
        {
            //positive
            frogloc += board[frogloc-1];
            hops++;
        }
        // Move frog left if on negative number
        else
        {
            //negative
            frogloc -= abs(board[frogloc-1]);
            hops++;
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