/*
 * File: CheckoutLineClass.cpp
 * ---------------------------------------
 * This program simulates a checkout line, customers arrive at the
 * checkout stand and get in line, those customers wait in the line
 * until the cashier is free, at which point they are served and occupy
 * the cashier for some period of time. After the service time is complete,
 * the cashier is free to serve the next customer.
 *
 * In each unit of time, up to the constant SIMULATION TIME:
 *
 * 1. Determine whether a new customer has arrived. New customers arrive
 * randomly, with a probability determined by the constant ARRIVAL_PROBABILITY
 *
 * 2. If the cashier is busy, note the cashier has spent another minute with
 * that customers. Eventually, the customer's time request is satisified
 */

#include <iostream>
#include <iomanip>
#include <queue>
#include "../random/random.h"
#include "../random/random.cpp"
using namespace std;

const double ARRIVAL_PROBABILITY = 0.05; /* probability that customers will arrive during a single unit of time */
const int MIN_SERVICE_TIME = 5;
const int MAX_SERVICE_TIME = 15;
const int SIMULATION_TIME = 2000;

class CheckoutLineSimulation
{
public:
    /*
     * Function: runSimulation
     * Usage: runSimulation();
     * ---------------------------------------
     * The number of customers served, the sum of customer waiting times,
     * the sum of queue length in each time step are returned through the
     * reference parameters.
     */
    void runSimulation(int &nServed, int &totalWait, int &totalLength)
    {
        queue<int> customerQueue;
        int timeRemaining = 0;
        nServed = 0;
        totalWait = 0;
        totalLength = 0;
        for (int t = 0; t < SIMULATION_TIME; t++)
        {
            if (randomChance(ARRIVAL_PROBABILITY))
                customerQueue.push(t);
            if (timeRemaining > 0)
                timeRemaining--;
            else if (!customerQueue.empty())
            {
                totalWait = totalWait + t - customerQueue.front();
                customerQueue.pop();
                nServed++;
                timeRemaining = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
            }
            totalLength += customerQueue.size();
        }
    }

    /*
     * Function: printReport()
     * Usage: printReport();
     * ---------------------------------------
     * Reports the result of simulation.
     */
    void printReport(int nServed, int totalWait, int totalLength)
    {
        cout << "Simulation results given the following constants:" << endl;
        cout << fixed << setprecision(2);
        cout << "SIMULATION_TIME: " << setw(7) << SIMULATION_TIME << endl;
        cout << "ARRIVAL_PROBABILITY: " << setw(7) << ARRIVAL_PROBABILITY << endl;
        cout << "MIN_SERVICE_TIME: " << setw(7) << MIN_SERVICE_TIME << endl;
        cout << "MAX_SERVICE_TIME: " << setw(7) << MAX_SERVICE_TIME << endl;
        cout << endl;
        cout << "Customers served: " << setw(7) << nServed << endl;
        cout << "Total waiting time: " << setw(7) << totalWait << endl;
        cout << "Average waiting time: " << setw(7) << double(totalWait) / nServed << endl;
        cout << "Total queue length: " << setw(7) << totalLength << endl;
        cout << "Average queue length: " << setw(7) << double(totalLength) / nServed << endl;
    }

private:
    int nServed;     /* number of customers served */
    int totalWait;   /* sum of all customers waiting time */
    int totalLength; /* sum of the queue length at each time step */
};

int main()
{
    CheckoutLineSimulation simulation;
    int nServed;
    int totalWait;
    int totalLength;
    simulation.runSimulation(nServed, totalWait, totalLength);
    simulation.printReport(nServed, totalWait, totalLength);
    return 0;
}