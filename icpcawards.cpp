#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int numTeams;
    cin >> numTeams;

    string school;
    string team;
    vector<string> winning_schools;
    vector<string> winning_teams;
    for (int i = 0; i < numTeams; i++)
    {
        cin >> school;
        cin >> team;

        if (std::find(winning_schools.begin(), winning_schools.end(), school) == winning_schools.end())
        {
            winning_schools.push_back(school);
            winning_teams.push_back(team);
        }
    }
    
    for (int i = 0; i < 12; i++)
    {
        cout << winning_schools[i] << " " << winning_teams[i] << endl;
    }
    return 0;
}