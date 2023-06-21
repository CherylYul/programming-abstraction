#include <iostream>
#include <map>
using namespace std;

int main()
{
    string allVotes = "MMMRMSSMSSMMMMMRRMMMMRRRMMM";
    map<char, int> voteTally;
    for (char c : allVotes)
        voteTally[c]++;
    for (auto c : voteTally)
        cout << c.first << " and " << c.second << endl;
    return 0;
}