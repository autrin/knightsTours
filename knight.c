#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * This is the Knight's Tour problem in C.
 * This program will output all the Knight's Tours on a 5x5 board size.
 */

#define N 5
#define BOARD_SIZE N *N
int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

bool isValidMove(int x, int y, int board[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && board[y][x] == 0);
}

void allToursFromCurrentSquare(int x, int y, int visited, int board[N][N], int visitedArr[25])
{
    board[y][x] = visited + 1;
    visitedArr[visited] = y * N + x + 1;

    if (visited == N * N - 1)
    { // found a tour
        for (int i = 0; i < N * N; i++)
        {
            printf("%d ", visitedArr[i]); // printing the tour
        }
        printf("\n");    // move to the next line for the next tour
        board[y][x] = 0; // backtracking
        visitedArr[visited] = -1;

        return; // response to the recursive call
    }

    for (int i = 0; i < 8; i++)
    {                                // going through the 8 moves to test them
        int nextX = x + moves[i][0]; // these are the new locations
        int nextY = y + moves[i][1]; // that we are considering for the knight

        if (isValidMove(nextX, nextY, board))
        {
            allToursFromCurrentSquare(nextX, nextY, visited + 1, board, visitedArr);
        }
    }
    board[y][x] = 0;
    visitedArr[visited] = -1;
}

void tourStarter()
{
    int board[N][N];
    int visitedArr[BOARD_SIZE]; // Array to track the visited sequence

    // Iterate over each cell of the board
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            // Reset the board and visited array for a new tour
            memset(board, 0, sizeof(board));
            memset(visitedArr, -1, sizeof(visitedArr));
            // Start a new tour from the current cell
            allToursFromCurrentSquare(col, row, 0, board, visitedArr);
        }
    }
}

int main(int argc, char *argv[])
{
    tourStarter();
    return 0;
}
