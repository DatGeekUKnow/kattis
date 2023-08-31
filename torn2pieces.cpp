#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Node
{
    public:
    Node()
    {

    }
    Node(string id)
    {
        Id = id;
    }
    string Id;
    vector<Node*> Adj;
    bool Visited = false;
};

vector<string> trail;
vector<Node*> locations;

string DFS(Node* place, Node* dest)
{
    place->Visited = true;
    if (place == dest) return place->Id;
    for (auto& i : place->Adj)
    {
        if (!i->Visited)
        {
            string result = DFS(i, dest);
            if (result != "") return (place->Id + " " + result);
        }
    }
    return "";
}

Node* findNode(string t, vector<Node*>& nodes)
{
    for (auto& nod : nodes)
    {
        if (t == nod->Id)
        {
            return nod;
        }
    }
    return nullptr;
}

int main()
{
    int numNodes;
    cin >> numNodes;

    string input; // will have at least two strings identifying a connection
    std::getline(cin, input); // throw away new line at the end
    for (int i = 0; i < numNodes; i++)
    {
        std::getline(cin, input);
        
        // reading in connections with indeterminate length
        std::stringstream ss(input);
        string s;
        vector<string> out;
        while (std::getline(ss, s, ' '))
        {
            out.push_back(s);
        }
        // assign values we've read in.
        // make sure this isn't a node we read in previously
        Node* current = findNode(out[0], locations);
        if (current == nullptr) // node doesn't exist
        {
            // Create new node (current) and push to locations
            string name = out[0];
            current = new Node(name);
            locations.push_back(current);
        }
        
        for (int i = 1; i < out.size(); i++)
        {
            // check if it's already in locations
            // if it is, push it to the adjacency list, else make a new node
            Node* connection = findNode(out[i], locations);
            if (connection == nullptr)
            {
                string name = out[i];
                connection = new Node(name);
                locations.push_back(connection);
            }
            if (findNode(out[i], current->Adj) == nullptr)
            {
                current->Adj.push_back(connection);
            }
            if (findNode(out[0], connection->Adj) == nullptr)
            {
                connection->Adj.push_back(current);
            }
        }
    }

    string start, finish;
    cin >> start >> finish;

    Node* startNode = findNode(start, locations);
    Node* destNode = findNode(finish, locations);

    string result = DFS(startNode, destNode);
    cout << ((result == "") ? "no route found" : result) << endl;

    for (auto n : locations)
    {
        delete n;
    }
    locations.clear();

    // all connections have been read in and established.
    return 0;
}