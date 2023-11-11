/*
 * Program: PegSolitaire.cpp
 * ---------------------------------------
 * This program solves the standard English Peg Solitaire puzzle using
 * backtracking strategy.
 * Ex: move peg position of (3, 1) to hole position of (3, 3):
 *           . . .                        . . .
 *           . . .                        . . .
 *       . . . . . . .                . . . . . . .
 *       . . . o . . .   --move-->    . o o . . . .
 *       . . . . . . .                . . . . . . .
 *           . . .                        . . .
 *           . . .                        . . .
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Position
{
    int x;
    int y;
    /*
     * The key of a map is of type "const Key", we can only perform operations
     * on the struct that are marked as const. Trying to use methods that are not
     * marked as const in that case results in the error.
     * Use struct as key in map: https://stackoverflow.com/questions/7204283/how-can-i-use-a-struct-as-key-in-a-stdmap
     * Operator overloading: https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading
     */
    bool operator==(const Position &p) const { return x == p.x && y == p.y; }
    bool operator<(const Position &p) const { return x < p.x || (x == p.x && y < p.y); }
};

enum Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

struct Move
{
    bool exist;
    Position start;  // Attacking peg's start position
    Position victim; // Position of peg getting jumped
    Position stop;   // Attacking peg's landing position
};

struct Game
{
    vector<string> Board;
    map<Position, map<Direction, Move>> ListAllMoves;
    int PegsRemains;
};

Game initGame();
void printBoard(vector<string> BoardGame);
bool isSolved(Game &BoardGame);
bool isSolved(Game &BoardGame, Position focus);
void makeMove(Game &BoardGame, Move move);
void unmakeMove(Game &BoardGame, Move move);
vector<Move> movablePegs(Game BoardGame, Position focus);
map<Direction, Move> moveAvailables(Game &BoardGame, Position point);
Direction operator++(Direction &dir);
Direction operator++(Direction &dir, int);

int main()
{
    Game PegSolitaire = initGame();
    if (isSolved(PegSolitaire))
    {
        cout << "Solved!" << endl;
        printBoard(PegSolitaire.Board);
    }
    return 0;
}

bool isSolved(Game &BoardGame)
{
    Position focus;
    focus.x = 3;
    focus.y = 3;
    return isSolved(BoardGame, focus);
}

bool isSolved(Game &BoardGame, Position focus)
{
    printBoard(BoardGame.Board);
    if (BoardGame.PegsRemains == 1 && BoardGame.Board[3][3] == '.')
        return true;
    for (Move move : movablePegs(BoardGame, focus))
    {
        makeMove(BoardGame, move);
        if (isSolved(BoardGame, move.stop))
            return true;
        unmakeMove(BoardGame, move);
    }
    return false;
}

void makeMove(Game &BoardGame, Move move)
{
    BoardGame.PegsRemains -= 1;
    BoardGame.Board[move.start.x][move.start.y] = 'o';
    BoardGame.Board[move.victim.x][move.victim.y] = 'o';
    BoardGame.Board[move.stop.x][move.stop.y] = '.';
}

void unmakeMove(Game &BoardGame, Move move)
{
    BoardGame.PegsRemains += 1;
    BoardGame.Board[move.start.x][move.start.y] = '.';
    BoardGame.Board[move.victim.x][move.victim.y] = '.';
    BoardGame.Board[move.stop.x][move.stop.y] = 'o';
}

vector<Move> movablePegs(Game BoardGame, Position focus)
{
    int sRow = focus.x - 2 > 0 ? focus.x - 2 : 0;
    int eRow = focus.x + 2 < 7 ? focus.x + 2 : 7;
    int sCol = focus.y - 2 > 0 ? focus.y - 2 : 0;
    int eCol = focus.y + 2 < 7 ? focus.y + 2 : 7;
    vector<Move> movables;
    for (int r = sRow; r <= eRow; r++)
    {
        for (int c = sCol; c <= eCol; c++)
        {
            if (BoardGame.Board[r][c] == '.')
            {
                Position point{r, c};
                for (Direction dir = NORTH; dir <= WEST; dir++)
                {
                    Move move = BoardGame.ListAllMoves[point][dir];
                    if (move.exist &&
                        BoardGame.Board[move.victim.x][move.victim.y] == '.' &&
                        BoardGame.Board[move.stop.x][move.stop.y] == 'o')
                        movables.push_back(move);
                }
            }
        }
    }
    return movables;
}

Game initGame()
{
    Game BoardGame;
    BoardGame.Board = {"  ...  ",
                       "  ...  ",
                       ".......",
                       "...o...",
                       ".......",
                       "  ...  ",
                       "  ...  "};
    BoardGame.PegsRemains = 32;
    for (int r = 0; r < 7; r++)
        for (int c = 0; c < 7; c++)
            if (BoardGame.Board[r][c] != ' ')
            {
                Position point{r, c};
                BoardGame.ListAllMoves.insert({point, moveAvailables(BoardGame, point)});
            }
    cout << "GAME INITIALIZATION:" << endl;
    cout << "The dot are pegs and o is the hole, you are allowed to" << endl;
    cout << "jump over 1 peg and remove that peg." << endl;
    printBoard(BoardGame.Board);
    return BoardGame;
}

map<Direction, Move> moveAvailables(Game &BoardGame, Position point)
{
    map<Direction, Move> moveDir = {{NORTH, Move{}},
                                    {EAST, Move{}},
                                    {SOUTH, Move{}},
                                    {WEST, Move{}}};
    for (Direction dir = NORTH; dir <= WEST; dir++)
    {
        moveDir[dir].start = point;
        switch (dir)
        {
        case NORTH:
            moveDir[dir].exist = point.x > 1;
            moveDir[dir].victim.x = point.x - 1;
            moveDir[dir].victim.y = point.y;
            moveDir[dir].stop.x = point.x - 2;
            moveDir[dir].stop.y = point.y;
            break;
        case EAST:
            moveDir[dir].exist = point.y < 5;
            moveDir[dir].victim.x = point.x;
            moveDir[dir].victim.y = point.y + 1;
            moveDir[dir].stop.x = point.x;
            moveDir[dir].stop.y = point.y + 2;
            break;
        case SOUTH:
            moveDir[dir].exist = point.x < 5;
            moveDir[dir].victim.x = point.x + 1;
            moveDir[dir].victim.y = point.y;
            moveDir[dir].stop.x = point.x + 2;
            moveDir[dir].stop.y = point.y;
            break;
        case WEST:
            moveDir[dir].exist = point.y > 1;
            moveDir[dir].victim.x = point.x;
            moveDir[dir].victim.y = point.y - 1;
            moveDir[dir].stop.x = point.x;
            moveDir[dir].stop.y = point.y - 2;
            break;
        }
    }
    return moveDir;
}

void printBoard(vector<string> BoardGame)
{
    for (string str : BoardGame)
        cout << str << endl;
    cout << endl;
}

Direction operator++(Direction &dir)
{
    dir = Direction(dir + 1);
    return dir;
}

Direction operator++(Direction &dir, int)
{
    Direction old = dir;
    dir = Direction(dir + 1);
    return old;
}