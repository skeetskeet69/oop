// Assignment 1 20T3 COMP1511: CS Paint
// paint.c
//
// This program was written by Daniel Wang (z5309511)
// on INSERT-DATE-HERE
//
// Version 1.0.0 (2020-10-04): Assignment released.

#include <stdio.h>

// The dimensions of the canvas (20 rows x 36 columns).
#define N_ROWS 20
#define N_COLS 36

// Shades (assuming your terminal has a black background).
#define BLACK 0
#define WHITE 4

// IF YOU NEED MORE #defines ADD THEM HERE


// Provided helper functions:
// Display the canvas.
void displayCanvas(int canvas[N_ROWS][N_COLS]);
// Clear the canvas by setting every pixel to be white.
void clearCanvas(int canvas[N_ROWS][N_COLS]);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE


int main(void) {
    int canvas[N_ROWS][N_COLS];

    clearCanvas(canvas);
    int instruction;
    while (scanf("%d", &instruction) == 1) {
        if (instruction == 1) {
            int start_row;
            int start_col;
            int end_row;
            int end_col;
            scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);
            if (start_col == end_col) {
                if (end_row < start_row) {
                    int temp = start_row;
                    start_row = end_row;
                    end_row = temp;
                }
                while (start_row <= end_row) {
                    canvas[start_row][start_col] = 0;
                    start_row++;
                }
                
            }
            else if (start_row == end_row) {
                if (end_col < start_col) {
                    int temp2 = start_col;
                    start_col = end_col;
                    end_col = temp2;
                }
                while (start_col <= end_col) {
                    canvas[start_row][start_col] = 0;
                    start_col++;
                }
            }
        }
    }

    


    // Hint: start by scanning in the command.
    //
    // If the command is the "Draw Line" command, scan in the rest of
    // the command (start row, start col, length, direction) and use
    // that information to draw a line on the canvas.
    //
    // Once your program can draw a line, add a loop to keep scanning
    // commands until you reach the end of input, and process each
    // command as you scan it.

    displayCanvas(canvas);

    return 0;
}



// ADD CODE FOR YOUR FUNCTIONS HERE



// Displays the canvas, by printing the integer value stored in
// each element of the 2-dimensional canvas array.
//
// You should not need to change the displayCanvas function.
void displayCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            printf("%d ", canvas[row][col]);
            col++;
        }
        row++;
        printf("\n");
    }
}


// Sets the entire canvas to be blank, by setting each element in the
// 2-dimensional canvas array to be WHITE (which is #defined at the top
// of the file).
//
// You should not need to change the clearCanvas function.
void clearCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            canvas[row][col] = WHITE;
            col++;
        }
        row++;
    }
}
