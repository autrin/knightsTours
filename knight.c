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
int main(int argc, char *argv[])
{   
    printf("Welcome to the Knight's Tour problem in C!\n");
    printf("Please enter the number of the rows of the chess board: ");
    printf("Enter the number of the columns of the chess board: ");
    int row, col = argv[1], argv[2]; // will be inputted to get any size for the board
    int visitedList[row * col];
    visitedList[0] = 1;
    // calls a function to print out all the knight tours
    for(int i = 0; i < row * col; i++){ // start from each square
        // calls a function to calculate the all the knight tours
        move(i, row, col, visitedList); 
    }
    // calls a function to print the number of all tours
    return 0;
}

// knights moves are +2+row.size, -2+row.size, -2row.size+1...
int move(int loc, int row, int col, int visitedList[])
{
    // start from the begenning an try a move. Go as long as long as i<=row*col and 
    // as long as the visited list is not full.
    // the 8 moves a knight can make:
    int m1 = +2 - col;
    int m2 = -2 - col;
    int m3 = -2*col + 1;
    int m4 = +col + 2;
    int m5 = +col - 2;
    int m6 = -2*col - 1;
    int m7 = +2*col + 1;
    int m8 = +2*col -1; 
    int moves[] = {m1, m2, m3, m4, m5, m6, m7, m8}; // a list of 8 moves

    int sizeOfVisited = sizeof(visitedList) / sizeof(visitedList[0]); // how many squares have been visited so far
    for(int k = 1; k <= row*col; k++){
        int m = m1;
        // now I had this location of mine
        // just add the move to it

        for(int l = 0; l < sizeOfVisited; l++){
            if(visitedList[l] == k){

            }

        }
    }

    int i = 1;
    bool visited = false;
    int newLoc;
    int* path = (int*)malloc(100 * sizeof(int));// paths that the knight has taken
    while (i <= row * col)
    {
        if (sizeOfVisited == row * col){ // Base case
                                        // has gone through all the squares, i.e. one tour done
            break;
        }
        
        newLoc = loc + m1;
        for(int j = 0; j < sizeOfVisited; j++){
            if(visitedList[j] == newLoc){
                visited = true; // try another direction
            }
        }
        if(visited == false){
            visitedList[sizeOfVisited] = newLoc;

        }
        // if(loc + se is not in visitedList){
        //     newLoc = loc + se;
        //     visitedList.add(newLoc);
        // }
        // else if(loc + sw is not in visitedList){
        //     newLoc = loc + sw;
        //     visitedList.add(newLoc);
        // }
        // else if(loc + uw is not in visitedList){
        //     newLoc = loc + uw;
        //     visitedList.add(newLoc);
        // }
        // else if(loc + ue is not in visitedList){
        //     newLoc = loc + ue;
        //     visitedList.add(newLoc);
        // }

        if(visited == true){
            // newLoc = loc + ue;
        }

    }
    // print the moves if led to a solution, i.e. the visitedList if full.
    sizeOfVisited = sizeof(visitedList) / sizeof(visitedList[0]);
    if (sizeOfVisted == row * col){
        printf("%d\n", visitedList);
    }
    return 0;
}

/*
recursive decent.
*/
