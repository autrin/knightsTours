#include <stdio.h>
#include <stdlib.h> // has malloc()
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>



#define BOARD_SIZE 5     // can be modified
#define MAXIMUM_SIZE 100 // will be used for the elements in the graph/dictionary

struct Pair
{
    int x;
    int y;
};
/**
 * This is the Knight's Tour problem in C.
 * This program will output all the Knight's Tours on any given board size.
 */

/*
recursive decent.
*/

// since this is a graph problem, we can use DFS algorithm.

/*
This function adds the edges between vertices. Edges are the paths that the knight has taken.
The vertices are teh squares of the chess board.
*/
// void addEdges(int loc, int row, int col, int visitedList[])
// {

// }

/*
Compares 2 integers
*/
int compareInts(int number1, int number2)
{
    if (number1 < number2)
        return -1;
    else if (number1 > number2)
        return 1;
    return 0;
}

int size = 0;                // keeps track of the last el in the array
int keys[MAXIMUM_SIZE][100]; // keys
int *k = keys;
int values[MAXIMUM_SIZE]; // values
/*
a utlility function to get the index of el in the graph
*/
int indexGetter(int key)
{
    for (int i = 0; i < size; i++)
    {
        if (compareInts(keys[i], key) == 0) // comparing the strings
        {
            return i;
        }
    }
    return -1;
}

/*
a utility function to insert the key-value in the dictionary
*/
void insertInDictionary(int key, int value)
{
    int idx = indexGetter(key);
    if (idx == -1)
    {                         // not present in the dictionary
        *keys[size] = key;    // TESTING
        values[size] = value; // inserted
    }
    else
    {                        // present in the dictionary
        values[idx] = value; // updated
    }
}

struct Pair validMoves[BOARD_SIZE * BOARD_SIZE]; // needs to be refreshed after every tour.
int lastInxOfValidMove;

void buildBoard()
{
    for (int row = 1; row <= BOARD_SIZE; row++)
    {
        for (int col = 1; col <= BOARD_SIZE; col++)
        {
            if (allowedMoves(row, col, BOARD_SIZE, validMoves))
            {

            }
        }
    }
}

/*
8 different directions for the knight to move.
*/
struct Pair moves[] = {
    {-1, -2},
    {1, -2},
    {-2, -1},
    {2, -1},
    {-2, 1},
    {2, 1},
    {-1, 2},
    {1, 2}};

/*
  utility function to get the valyue of the key in the dictionary
  */
int getValueFromDictionary(int key[])
{
    int idx = indexGetter(key);
    if (idx == -1)
    { // not present in the dictionary
        return -1;
    }
    else
    { // present in the dictionary
        return values[idx];
    }
}

bool allowedMoves(int row, int col, int boardSize, struct Pair validMoves[])
{
    struct Pair newLoc;
    for (int i = 0; i < 8; i++)
    {
        newLoc.x = row + validMoves[i].x;
        newLoc.y = col + validMoves[i].y;
        if (newLoc.x >= 0 && newLoc.x < BOARD_SIZE && newLoc.y >= 0 && newLoc.y < BOARD_SIZE)
        {
            validMoves[lastInxOfValidMove] = newLoc; // storing the valid move
            return true;
        }
    }
    return false;
}
