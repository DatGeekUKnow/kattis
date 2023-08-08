#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::reverse;

class Node
{
    public:
    int id;
    vector<int> adj;
    bool visited = false;
};

vector<Node> contestants;
vector<int> visited;

void DFS(Node &person)
{
    person.visited = true;
    visited.push_back(person.id);
    for (auto& i : person.adj)
    {
        if (!contestants[i].visited)
        {
            DFS(contestants[i]);
        }
    }
}

int main()
{
    int length; // number of contestants
    cin >> length;

    char eval; // either 1, 0, or X

    contestants.resize(length);
    for (int i = 0; i < length; i++)
    {
        // read in contestant[i] adjacency list
        contestants[i].id = i;
        for (int j = 0; j < length; j++)
        {
            // if 1, add j to i's adjacency list
            cin >> eval;
            if (eval == '1') contestants[i].adj.push_back(j);
        }
    }
    DFS(contestants[0]);

    if (visited.size() == contestants.size())
    {
        reverse(visited.begin(), visited.end());

        for (int i : visited)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "impossible";
    }
    return 0;
}