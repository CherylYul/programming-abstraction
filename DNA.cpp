/*
 * File: DNA.cpp
 * -----------------------
 * Find matching position given 2 DNAs
 */

#include <iostream>
#include <cctype>
#include <map>
using namespace std;

map<char, char> DNA_RULES = {{'A', 'T'}, {'C', 'G'}, {'G', 'C'}, {'T', 'A'}};
int findMatchDNA(string strand, string DNA);
int findMatchDNA(string strand, string DNA, int start);

int main()
{
    string strand1;
    cout << "Enter DNA: " << endl;
    getline(cin, strand1);
    string strand2;
    cout << "Enter strand: " << endl;
    getline(cin, strand2);
    cout << findMatchDNA(strand2, strand1) << endl;
    return 0;
}

int findMatchDNA(string strand, string DNA) { return findMatchDNA(strand, DNA, 0); }
int findMatchDNA(string strand, string DNA, int start)
{
    string matchingStrand = "";
    for (int i = 0; i < strand.length(); i++)
        matchingStrand += DNA_RULES[strand[i]];
    return DNA.substr(start).find(matchingStrand);
}