/*
 * File: Nim.cpp
 * ---------------------------------------
 * This program simulates a simple variant game of Nim. The game starts
 * with 13 coins, players take turn removing 1, 2, or 3 coins, the person
 * who takes the last will lose.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int COINS = 13;
const int MAX_MOVE = 3;
const int NO_GOOD_MOVE = -1;
const int WINNING_POSITION = 1000;
const int LOSING_POSITION = -WINNING_POSITION;
const int MAX_DEPTH = 5;

void error(string msg);
struct Move
{
    int nTaken;
};

enum Player
{
    HUMAN,
    COMPUTER
};

/*
 * Method: opponent
 * Usage: Player other = opponent(player);
 * ---------------------------------------
 * Returns the opponent of the player. The opponent of the computer is the
 * human player and vice versa.
 */

Player opponent(Player player) { return (player == HUMAN) ? COMPUTER : HUMAN; }
const Player STARTING_PLAYER = HUMAN;

class SimpleNim
{
public:
    /*
     * Method: play
     * Usage: game.play();
     * ---------------------------------------
     * Plays one game of Nim with the human player.
     */
    void play()
    {
        nCoins = COINS;
        whoseTurn = STARTING_PLAYER;
        while (nCoins > 1)
        {
            cout << "There are " << nCoins << " coins in the pile." << endl;
            if (whoseTurn == HUMAN)
                nCoins -= getUserMove();
            else
            {
                int nTaken = getComputerMove();
                cout << "I'll take " << nTaken << "." << endl;
                nCoins -= nTaken;
            }
            whoseTurn = opponent(whoseTurn);
        }
        announceResult();
    }

    /*
     * Method: printInstructions
     * Usage: game.printInstructions();
     * ---------------------------------------
     * This method explains the rules of the game to user.
     */
    void printInstructions()
    {
        cout << "Welcome to the game of Nim!" << endl;
        cout << "In this game, we will start with the pile of " << COINS << endl;
        cout << "coins on the table. On each turn, you and I will" << endl;
        cout << "alternatively take between 1 and " << MAX_MOVE << "coins from" << endl;
        cout << "the table. The player who takes that last coins loses." << endl
             << endl;
    }

private:
    /*
     * Method: getComputerMove
     * Usage: int nTaken = getComputerMove();
     * ---------------------------------------
     * Figures out what move is best for computer and returns number of coins taken.
     */
    int getComputerMove()
    {
        int nTaken = findGoodMove(nCoins);
        return (nTaken == NO_GOOD_MOVE) ? 1 : nTaken;
    }

    /*
     * Method: findGoodMove
     * Usage: int nTaken = findGoodMove(nCoins);
     * ---------------------------------------
     * Looks for a winning move, given the specified number of coins. If there is a
     * winning move in that position, the method returns that value; if not the methods
     * return NO_GOOD_MOVE
     */
    int findGoodMove(int nCoins)
    {
        int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
        for (int nTaken = 1; nTaken <= limit; nTaken++)
            if (isBadPosition(nCoins - nTaken))
                return nTaken;
        return NO_GOOD_MOVE;
    }

    /*
     * Method: isBadPosition
     * Usage: if (isBadPosition(nCoins)) ...
     * ---------------------------------------
     * This method returns true if nCoins is a bad position. A bad position
     * is one in which there is no good move
     */
    bool isBadPosition(int nCoins)
    {
        if (nCoins == 1)
            return true;
        return findGoodMove(nCoins) == NO_GOOD_MOVE;
    }

    // /*
    //  * Method: findBestMove
    //  * Usage: Move move = findBestMove();
    //  *        Move move = findBestMove(depth, rating);
    //  * ---------------------------------------
    //  * Finds the best move for the current player and returns that move as the value
    //  * of the function. The second form is used for later recursive calls and includes
    //  * 2 parameters. The depth parameter is used to limit the depth of the search for
    //  * the games that are too difficult to analyze. The rating is used to store the
    //  * rating of the best move.
    //  */

    // Move findBestMove()
    // {
    //     int rating;
    //     return findBestMove(0, rating);
    // }

    // Move findBestMove(int depth, int &rating)
    // {
    //     vector<Move> moveList;
    //     Move bestMove;
    //     int minRating = WINNING_POSITION + 1;
    //     generateMoveList(moveList);
    //     if (moveList.isEmpty())
    //         error("No move available!");
    //     for (Move move : moveList)
    //     {
    //         makeMove(move);
    //         int moveRating = evaluatePosition(depth + 1);
    //         if (moveRating < minRating)
    //         {
    //             bestMove = move;
    //             minRating = moveRating;
    //         }
    //         retractMove(move);
    //     }
    //     rating = -minRating;
    //     return bestMove;
    // }

    // /*
    //  * Method: evaluatePosition
    //  * Usage: int rating = evaluatePosition(rating);
    //  * ---------------------------------------
    //  * Evaluates a position by finding the rating of the best move starting at
    //  * that point. The depth parameter is used to limit the search depth.
    //  */

    // int evaluatePosition(int depth) {
    //     if (gameIsOver() || depth >= MAX_DEPTH)
    //         return evaluateStaticPosition();
    //     int rating;
    //     findBestMove(depth, rating);
    //     return rating;
    // }

    /*
     * Method: getUserMove
     * Usage: int nTaken = getUserMove();
     * ---------------------------------------
     * Asks the user to enter a move and returns the number of coins taken.
     */
    int
    getUserMove()
    {
        while (true)
        {
            int nTaken;
            cout << "How many would you like?" << endl;
            cin >> nTaken;
            int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
            if (nTaken > 0 && nTaken <= limit)
                return nTaken;
            cout << "That's a cheating! Please choose a valid number!" << endl;
        }
    }

    /*
     * Method: announceResult
     * Usage: announceResult();
     * ---------------------------------------
     * Announces the final result
     */
    void announceResult()
    {
        if (nCoins == 0)
            cout << "You took the last coin. You lose." << endl;
        else
        {
            cout << "There is one coin left." << endl;
            if (whoseTurn == HUMAN)
                cout << "I win" << endl;
            else
                cout << "I lose" << endl;
        }
    }

    int nCoins;
    Player whoseTurn;
};

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

int main()
{
    SimpleNim game;
    game.printInstructions();
    game.play();
    return 0;
}