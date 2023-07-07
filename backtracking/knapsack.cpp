/*
 * Knapsack Problem
 * ---------------------------------------
 * Given a target weight and a set of objects in which each object has a value
 * and a weight, determine a subset of objects such that the sum of their weights
 * is less than or equal to the target weight and the sum of their values is maximized.
 */

#include <iostream>
#include <vector>
using namespace std;

struct objectT
{
    int weight;
    int value;
};

int fillKnapsack(vector<objectT> &objects, int targetWeight);
int fillKnapsack(vector<objectT> &objects, int weight, int currentScore);
int fillKnapsack(vector<objectT> &objects,
                 int weight, int currentScore,
                 vector<objectT> &currentSolutionObjects,
                 vector<objectT> &bestSolutionObjects);
void findAllKnapsackSolutions(vector<objectT> &objects,
                              int targetWeight,
                              vector<vector<objectT>> &allSolutions);
void findAllKnapsackSolutions(vector<objectT> &objects,
                              int weight,
                              vector<objectT> &potentialSolution,
                              vector<vector<objectT>> &allSolutions);
void printObjects(vector<objectT> objects);
void printAllSolutions(vector<vector<objectT>> allSolutions);

int main()
{
    objectT obj1;
    obj1.value = 4;
    obj1.weight = 12;
    objectT obj2;
    obj2.value = 2;
    obj2.weight = 1;
    objectT obj3;
    obj3.value = 10;
    obj3.weight = 4;
    objectT obj4;
    obj4.value = 1;
    obj4.weight = 1;
    objectT obj5;
    obj5.value = 2;
    obj5.weight = 2;
    vector<objectT> objects = {obj1, obj2, obj3, obj4, obj5};
    vector<objectT> currentSol;
    vector<objectT> bestSol;
    // vector<vector<objectT>> allSolutions;
    // findAllKnapsackSolutions(objects, 15, allSolutions);
    // printAllSolutions(allSolutions);
    cout << fillKnapsack(objects, 15, 0, currentSol, bestSol) << endl;
    printObjects(bestSol);
    return 0;
}

/*
 * Backtracking: not for optimization problem, just for going all possible solutions
 * 1. Keep track of the weight and keep track of the best total value "score"
 * 2. Loop over all items, adding value to the knapsack, and subtracting the weight
 * of items from the total weight allowed.
 * 3. If the weight goes below zero, we have too many items.
 *
 * Why didn't save the recursive calls when weight reach 0? This is a style issue, which
 * is anti-pattern arms-length recursion, instead let the base case stop recursion, we
 * reach ahead and handle it in the current state
 */
int fillKnapsack(vector<objectT> &objects, int targetWeight)
{
    return fillKnapsack(objects, targetWeight, 0);
}

int fillKnapsack(vector<objectT> &objects, int weight, int currentScore)
{
    // Base case 1: weight is decreasing when adding elements, when it goes below 0, we return 0
    if (weight < 0)
        return 0;
    // Base case 2: we have exhausted the objects vector, we need return current score
    if (objects.empty())
        return currentScore;

    // Access and remove the object we gonna check
    objectT originalObject = objects.back();
    objects.pop_back();

    // Recursively call the function without adding the object
    int scoreWithoutObject = fillKnapsack(objects, weight, currentScore);
    // Recursively call the function adding the object
    int scoreWithObject = fillKnapsack(objects, weight - originalObject.weight,
                                       currentScore + originalObject.value);
    // Backtrack
    objects.push_back(originalObject);
    return max(scoreWithObject, scoreWithoutObject);
}

/*
 * Find the actual objects in the knapsack for the best solution
 */
int fillKnapsack(vector<objectT> &objects,
                 int weight, int currentScore,
                 vector<objectT> &currentSolutionObjects,
                 vector<objectT> &bestSolutionObjects)
{
    if (weight < 0)
        return 0;

    /*
     * Now we keep track of not only the best total solution, but we have to pass
     * along the current solution so that we can calculate whether we have a better
     * solution, and keep track of it throughout the recursion.
     */
    if (objects.empty())
    {
        printObjects(currentSolutionObjects);
        int bestScoreSoFar = 0;
        for (objectT obj : bestSolutionObjects)
            bestScoreSoFar += obj.value;
        if (currentScore > bestScoreSoFar)
            bestSolutionObjects = currentSolutionObjects;
        return currentScore;
    }

    // Access and remove the object we gonna check
    objectT originalObject = objects.back();
    objects.pop_back();

    // Recursively call the function without adding the object
    int scoreWithoutObject = fillKnapsack(objects, weight, currentScore,
                                          currentSolutionObjects, bestSolutionObjects);
    // Recursively call the function adding the object
    int newWeight = weight - originalObject.weight;
    int newScore = currentScore + originalObject.value;
    currentSolutionObjects.push_back(originalObject); // put the current object to the solution bag
    int scoreWithObject = fillKnapsack(objects, newWeight, newScore,
                                       currentSolutionObjects, bestSolutionObjects);
    // Backtrack
    currentSolutionObjects.pop_back(); // remove the object from the current solution
    objects.push_back(originalObject);
    return max(scoreWithObject, scoreWithoutObject);
}

// Finding all knapsack solutions
void findAllKnapsackSolutions(vector<objectT> &objects,
                              int targetWeight,
                              vector<vector<objectT>> &allSolutions)
{
    vector<objectT> potentialSolution;
    findAllKnapsackSolutions(objects, targetWeight, potentialSolution, allSolutions);
}
void findAllKnapsackSolutions(vector<objectT> &objects,
                              int weight,
                              vector<objectT> &potentialSolution,
                              vector<vector<objectT>> &allSolutions)
{
    if (weight < 0)
        return;
    allSolutions.push_back(potentialSolution); // if we made it here, we have a solution!

    for (int i = 0; i < objects.size(); i++)
    {
        objectT originalObject = objects[i];
        objects.erase(objects.begin() + i);
        potentialSolution.push_back(originalObject);

        int currWeight = weight - originalObject.weight;
        findAllKnapsackSolutions(objects, currWeight, potentialSolution, allSolutions);

        objects.insert(objects.begin() + i, originalObject);
        potentialSolution.pop_back();
    }
}

void printObjects(vector<objectT> objects)
{
    cout << "Print objects: " << endl;
    for (objectT obj : objects)
        cout << "{ " << obj.value << ", " << obj.weight << "}" << endl;
}

void printAllSolutions(vector<vector<objectT>> allSolutions)
{
    int i = 0;
    for (vector<objectT> objs : allSolutions)
    {
        cout << "Objects " << i++ << endl;
        for (objectT obj : objs)
            cout << "{ " << obj.value << ", " << obj.weight << "}" << endl;
    }
}