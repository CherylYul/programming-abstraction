/*
 * File: card.h
 * ---------------------------------------
 * This interface exports class that represents standard playing card
 */

#ifndef _card_h
#define _card_h
#include <string>
#include <cstring>

enum Suit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
};

enum Rank
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Card
{
public:
    /*
     * Constructor: Card
     * Usage: Card zero;
     *        Card card(str);
     *        Card card(r, s);
     *        Card card(r, s);
     * ---------------------------------------
     * 1. Default constructor, when using this need assign value for the card later
     * 2. Takes a short string name of "10S", "JD" or "AC"
     * 3. Take seperate values for rank and suit in the string type
     * 4. Take seperate values for rank and suit in specified Rank and Suit type
     */

    Card();
    Card(std::string card);
    Card(std::string r, std::string s);
    Card(Rank r, Suit s);

    std::string toString();
    std::string getRank();
    std::string getSuit();

    // friend Rank operator++(Rank r);
    // friend Suit operator++(Suit s);
    friend int countSubsetSum(std::vector<Card> cards, int target);

private:
    Rank cardRank;
    Suit cardSuit;
    Rank stringToRank(std::string str);
    Suit stringToSuit(std::string str);
    std::string rankToString(Rank r);
    std::string suitToString(Suit s);
    int rankToInteger(Rank r);
};

std::ostream &operator<<(std::ostream &os, Card card);
Rank operator++(Rank &r, int);
Suit operator++(Suit &s, int);
int countSubsetSum(std::vector<Card> cards, int target);
void displayCard();

#endif