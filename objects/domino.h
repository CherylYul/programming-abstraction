/*
 * File: domino.h
 * ---------------------------------------
 * This interface exports a class for representing domino numbers.
 */

#ifndef _domino_h
#define _domino_h
#include <string>

class Domino
{
public:
    /*
     * Costructor: Domino
     * Usage: Domino zero;
     *        Domino d(x, y);
     * ---------------------------------------
     * A default constructor creates the 0-0 domino
     * A constructor takes number of dot corresponding 2 domino's value
     */
    Domino();
    Domino(int x, int y);

    /*
     * Method: toString
     * Usage: string str = d.toString();
     * ---------------------------------------
     * Returns the string represetation of this domino number
     */

    std::string toString();

    /*
     * Method: getLeftDots, getRightDots, getTotalDots
     * Usage: int leftDots = d.getLeftDots();
     *        int rightDots = d.getRightDots();
     *        int getTotalDots = d.getTotalDots();
     * ---------------------------------------
     * Returns the value of left dots, right dots and total dots value
     */

    int getLeftDots();
    int getRightDots();
    int getTotalDots();

    /* Declare operator functions as friends */

    friend Domino operator+(Domino d1, Domino d2);
    friend Domino operator-(Domino d1, Domino d2);
    friend Domino operator*(Domino d1, Domino d2);
    friend Domino operator/(Domino d1, Domino d2);

private:
    int leftDots;
    int rightDots;
};

std::ostream &operator<<(std::ostream &os, Domino d);
Domino operator+(Domino d1, Domino d2);

#endif