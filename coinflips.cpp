/*
 * File: coinflips
 * -----------------------------------------------
 * Simulates the action of flipping a coin, stops when it produces
 * consecutives 3 heads.
 */

#include <iostream>
#include "random/random.h"
#include "random/random.cpp"
using namespace std;

class Coin
{
public:
    /*
     * Constructor: Coin
     * Usage: Coin coin;
     *        Coin coin(headProb);
     * -----------------------------------------------
     * 1. Default constructor sets the prob of heads = tails = 0.5
     * 2. Manually set the prob of heads, then auto calculate the prob of tails
     */

    Coin()
    {
        head = 0.5;
        tail = 0.5;
    }

    Coin(double headProb)
    {
        head = headProb;
        tail = 1 - headProb;
    }

    /*
     * Methods: getHeadProb, getTailProb
     * Usage: double h = coin.getHeadProb();
     *        double t = coin.getTailProb();
     * -----------------------------------------------
     * These methods returns the prob of heads and tails of this coin
     */

    double getHeadProb() { return head; }
    double getTailProb() { return tail; }

    /*
     * Method: flipCoins
     * Usage: string str = coin.flipCoins();
     * -----------------------------------------------
     * Returns Heads or Tails based on probability ratio
     */

    string flipCoins()
    {
        initRandomSeed();
        double prob = rand() / (double(RAND_MAX) + 1);
        if (prob <= head)
            return "Heads";
        else
            return "Tails";
    }

    /*
     * Method: consecutiveSequence
     * Usage: coin.consecutiveSequence(k, "Heads");
     *        coin.consecutiveSequence(k, "Tails");
     * -----------------------------------------------
     * Simulates the number of times the coin have to flips to get the consecutive
     * sequence of "Heads" or "Tails" k times
     */

    void consecutiveSequence(int k, string HeadsOrTails)
    {
        int count = 0;
        int flipTimes = 0;
        while (count != k)
        {
            if (flipCoins() == HeadsOrTails)
                count++;
            else
                count = 0;
            flipTimes++;
        }
        cout << "It took " << flipTimes << " flips to get "
             << k << " consecutive " << HeadsOrTails << endl;
    }

private:
    double head;
    double tail;
};

int main()
{
    Coin cf(0.8);
    cf.consecutiveSequence(3, "Heads");
    return 0;
}
