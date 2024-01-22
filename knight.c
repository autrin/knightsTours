#include <stdio.h>
#include <stdlib.h> // has malloc()
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

/*
    1. Graph Representation: Use a 2D array to represent the chessboard.
    2. DFS Function: Implement DFS using recursion in C.
    3. Tracking Visited Nodes: Use an additional 2D array or 1D array (since the board is 5x5) to keep track of visited squares.
    4. Storing and Printing the Tour: Since C doesn’t have dynamic arrays like Python, we will use a fixed-size array
        (size 25 for a 5x5 board) to store the tour and print it when a full tour is found.
*/

// #define BOARD_SIZE 5     // can be modified
// #define MAXIMUM_SIZE 100 // will be used for the elements in the graph/dictionary


// struct Pair
// {
//     int x;
//     int y;
// };
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
// int compareInts(int number1, int number2)
// {
//     if (number1 < number2)
//         return -1;
//     else if (number1 > number2)
//         return 1;
//     return 0;
// }

// int size = 0;                // keeps track of the last el in the array
// int keys[MAXIMUM_SIZE][100]; // keys
// int *k = keys;
// int values[MAXIMUM_SIZE]; // values
// /*
// a utlility function to get the index of el in the graph
// */
// int indexGetter(int key)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (compareInts(keys[i], key) == 0) // comparing the strings
//         {
//             return i;
//         }
//     }
//     return -1;
// }

/*
a utility function to insert the key-value in the dictionary
*/
// void insertInDictionary(int key, int value)
// {
//     int idx = indexGetter(key);
//     if (idx == -1)
//     {                         // not present in the dictionary
//         *keys[size] = key;    // TESTING
//         values[size] = value; // inserted
//     }
//     else
//     {                        // present in the dictionary
//         values[idx] = value; // updated
//     }
// }

// struct Pair validMoves[BOARD_SIZE * BOARD_SIZE]; // needs to be refreshed after every tour.
// int lastInxOfValidMove;

// void buildBoard()
// {
//     for (int row = 1; row <= BOARD_SIZE; row++)
//     {
//         for (int col = 1; col <= BOARD_SIZE; col++)
//         {
//             if (allowedMoves(row, col, BOARD_SIZE, validMoves))
//             {

//             }
//         }
//     }
// }

/*
8 different directions for the knight to move.
*/
// struct Pair moves[] = {
//     {-1, -2},
//     {1, -2},
//     {-2, -1},
//     {2, -1},
//     {-2, 1},
//     {2, 1},
//     {-1, 2},
//     {1, 2}};

/*
  utility function to get the valyue of the key in the dictionary
  */
// int getValueFromDictionary(int key[])
// {
//     int idx = indexGetter(key);
//     if (idx == -1)
//     { // not present in the dictionary
//         return -1;
//     }
//     else
//     { // present in the dictionary
//         return values[idx];
//     }
// }

// bool allowedMoves(int row, int col, int boardSize, struct Pair validMoves[])
// {
//     struct Pair newLoc;
//     for (int i = 0; i < 8; i++)
//     {
//         newLoc.x = row + validMoves[i].x;
//         newLoc.y = col + validMoves[i].y;
//         if (newLoc.x >= 0 && newLoc.x < BOARD_SIZE && newLoc.y >= 0 && newLoc.y < BOARD_SIZE)
//         {
//             validMoves[lastInxOfValidMove] = newLoc; // storing the valid move
//             return true;
//         }
//     }
//     return false;
// }

#define N 5
#define BOARD_SIZE N * N

int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

bool isValidMove(int x, int y, int board[BOARD_SIZE]) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x * N + y] == -1);
}

int getDegree(int x, int y, int board[BOARD_SIZE]) { // the number of the valid moves
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (isValidMove(x + moves[i][0], y + moves[i][1], board)) {
            count++;
        }
    }
    return count;
}

/*
function to sort the array of moves based on Warnsdorff's heuristic
*/
void sortMoves(int *startX, int *startY, int board[BOARD_SIZE], int num) {
    int min_deg_idx, min_deg, nxt_x, nxt_y, degree;
    int tmp_x, tmp_y;

    for (int i = 0; i < num; ++i) {
        min_deg_idx = -1;
        min_deg = 9;  // Any number larger than the maximum possible degree

        // Get the degree of each move
        for (int j = i; j < num; ++j) {
            nxt_x = startX[i] + moves[j][0];
            nxt_y = startY[i] + moves[j][1];
            degree = getDegree(nxt_x, nxt_y, board);

            // Update the index of the move with the minimum degree
            // meaning the square with the minimum number of valid moves
            if (degree < min_deg) {
                min_deg_idx = j;
                min_deg = degree;
            }
        }

        // Swap the move with the minimum degree with the current move
        if (min_deg_idx != -1) {
            tmp_x = startX[i];
            tmp_y = startY[i];
            startX[i] = startX[min_deg_idx];
            startY[i] = startY[min_deg_idx];
            startX[min_deg_idx] = tmp_x;
            startY[min_deg_idx] = tmp_y;
        }
    }
}


bool solveKTUtil(int x, int y, int movei, int board[BOARD_SIZE]) {
    if (movei == BOARD_SIZE) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("%d", board[i]);
            printf(",");
        }
        printf("\n");
        return false; // Changed to false to continue finding other tours
    }

    int nextX[8], nextY[8];
    for (int k = 0; k < 8; k++) {
        nextX[k] = x + moves[k][0];
        nextY[k] = y + moves[k][1];
    }

    sortMoves(nextX, nextY, board, 8);

    for (int i = 0; i < 8; i++) {
        if (isValidMove(nextX[i], nextY[i], board)) {
            board[nextX[i] * N + nextY[i]] = movei;
            if (solveKTUtil(nextX[i], nextY[i], movei + 1, board)) {
                // return true;
            }
            board[nextX[i] * N + nextY[i]] = -1; // Backtracking
        }
    }
    return false;
}

bool solveKT() {
    int board[BOARD_SIZE];

    for (int start = 0; start < BOARD_SIZE; start++) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            board[i] = -1;
        }

        int startX = start / N;
        int startY = start % N;
        board[startX * N + startY] = 0;

        solveKTUtil(startX, startY, 1, board);
        // now for the next iteration that starts from another square,
        // we refresh the board by assigning -1 to all the squares in the
        // inner for loop.
    }
    return true;
}

int main(int argc, char *argv[]){
    solveKT();
    return 0;
}