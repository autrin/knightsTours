#include <stdio.h>
#include <stdlib.h> // has malloc()
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

/**
 * This is the Knight's Tour problem in C.
 * This program will output all the Knight's Tours on any given board size.
 */

#define N 5
#define BOARD_SIZE N * N
bool possible  = false; // possible tour
int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
int board[N][N];

bool isValidMove(int x, int y, int board[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0);
}

void solveKTUtil(int x, int y, int visited, int board[N][N]) {
    // FIXME: Print the order of visiting the squares, not the chess board
    board[x][y] = visited;
    // calculate the square
    int square = x + y * N; // doesnt seem right
    printf("%d", square);
    printf("\n");
    if(visited == N*N){ // found a tour
        possible = true;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                printf("%d,", board[i][j]); // printing the tour
            }
        }
        printf("\n"); // move to the next line for the next tour
        board[x][y] = 0; // backtracking
        return; // response to the recursive call
    }

    for (int i = 0; i < 8; i++) { // going through the 8 moves to test them
        int nextX = x + moves[i][0]; // these are the new locations
        int nextY = y + moves[i][1]; // that we are considering for the knight

        if(isValidMove(nextX, nextY, board)) {
            solveKTUtil(nextX, nextY, visited+1, board);
        }
    }
    board[x][y] = 0;
}

void solveKT() {
    int x = 1;
    int y = 1;

    for (int start = 0; start < BOARD_SIZE; start++) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            board[start][i] = 0;
        }

        solveKTUtil(start, y-1, 1, board);
        y+=1;
        
        // now for the next iteration that starts from another square,
        // we refresh the board by assigning -1 to all the squares in the
        // inner for loop.
    }
    // solveKTUtil(x-1, y-1, 1, board);

}

int main(int argc, char *argv[]){
    solveKT();
    return 0;
}
