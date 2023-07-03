/*
 * File: card.cpp
 * ---------------------------------------
 * This implements card class
 */

#include "card.h"
#include <iostream>
#include <vector>
using namespace std;

Card::Card() {}

Card::Card(string card)
{
    string guessRank = card.substr(0, card.length() - 1);
    string guessSuit = card.substr(card.length() - 1, 1);
    cardRank = stringToRank(guessRank);
    cardSuit = stringToSuit(guessSuit);
}

Card::Card(string r, string s)
{
    cardRank = stringToRank(r);
    cardSuit = stringToSuit(s);
}

Card::Card(Rank r, Suit s)
{
    cardRank = r;
    cardSuit = s;
}

string Card::toString()
{
    return rankToString(cardRank) + suitToString(cardSuit);
}

string Card::getRank()
{
    return rankToString(cardRank);
}

string Card::getSuit()
{
    return suitToString(cardSuit);
}

Rank Card::stringToRank(string str)
{
    if (str == "10")
        return Rank(Ten);
    switch (str.c_str()[0])
    {
    case '2':
        return Rank(Two);
    case '3':
        return Rank(Three);
    case '4':
        return Rank(Four);
    case '5':
        return Rank(Five);
    case '6':
        return Rank(Six);
    case '7':
        return Rank(Seven);
    case '8':
        return Rank(Eight);
    case '9':
        return Rank(Nine);
    case 'J':
        return Rank(Jack);
    case 'Q':
        return Rank(Queen);
    case 'K':
        return Rank(King);
    default:
        return Rank(Ace);
    }
}

Suit Card::stringToSuit(string str)
{
    switch (str.c_str()[0])
    {
    case 'C':
        return Suit(CLUBS);
    case 'D':
        return Suit(DIAMONDS);
    case 'H':
        return Suit(HEARTS);
    default:
        return Suit(SPADES);
    }
}

string Card::rankToString(Rank r)
{
    switch (r)
    {
    case Two:
        return "2";
    case Three:
        return "3";
    case Four:
        return "4";
    case Five:
        return "5";
    case Six:
        return "6";
    case Seven:
        return "7";
    case Eight:
        return "8";
    case Nine:
        return "9";
    case Ten:
        return "10";
    case Jack:
        return "J";
    case Queen:
        return "Q";
    case King:
        return "K";
    case Ace:
        return "A";
    default:
        return "Invalid";
    }
}

string Card::suitToString(Suit s)
{
    switch (s)
    {
    case CLUBS:
        return "C";
    case DIAMONDS:
        return "D";
    case HEARTS:
        return "H";
    case SPADES:
        return "S";
    default:
        return "Invalid";
    }
}

int Card::rankToInteger(Rank r)
{
    switch (r)
    {
    case Two:
        return 2;
    case Three:
        return 3;
    case Four:
        return 4;
    case Five:
        return 5;
    case Six:
        return 6;
    case Seven:
        return 7;
    case Eight:
        return 8;
    case Nine:
        return 9;
    case Ten:
    case Jack:
    case Queen:
    case King:
        return 10;
    case Ace:
        return 1;
    default:
        return 0;
    }
}

ostream &operator<<(ostream &os, Card card)
{
    return os << card.toString();
}

Rank operator++(Rank &r, int)
{
    Rank old = r;
    r = Rank(r + 1);
    return old;
}

Suit operator++(Suit &s, int)
{
    Suit old = s;
    s = Suit(s + 1);
    return old;
}

/*
 * Function: countSubsetSum
 * Usage: int n = countSubsetSum(cards, target);
 * ---------------------------------------
 * Count the subset of cards that add to a target number. Ex, in Cribbage
 * game, playing 5 cards: AD, 5C, 10S, 4H, 9C have 3 ways to sum to 15:
 * AD + 10S + 4H, AD + 5C + 9C, 5C + 10S
 *     Card card1("AD"); Card card2("5C"); Card card3("10S");
 *     Card card4("4H"); Card card5("9C"); Card card6("5D");
 *     Card card7("5H"); Card card8("5S"); Card card9("JC");
 *     vector<Card> cards = {card2, card6, card7, card8, card9}; // 8
 *     vector<Card> cards = {card1, card2, card3, card4, card5}; // 3
 *     cout << countSubsetSum(cards, 15) << endl;
 */

int countSubsetSum(vector<Card> cards, int target)
{
    if (cards.empty())
    {
        if (target == 0)
            return 1;
        else
            return 0;
    }
    Card cardN = cards.back();
    int value = cardN.rankToInteger(cardN.cardRank);
    cards.pop_back();
    return countSubsetSum(cards, target) + countSubsetSum(cards, target - value);
}

void displayCard()
{
    for (Suit suit = CLUBS; suit <= SPADES; suit++)
    {
        for (Rank rank = Two; rank <= Ace; rank++)
            cout << " " << Card(rank, suit);
        cout << endl;
    }
}