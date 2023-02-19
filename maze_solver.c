#include <stdio.h>
#define MAX_SIZE 20

int maze[MAX_SIZE][MAX_SIZE], solution[MAX_SIZE][MAX_SIZE];
int rows, cols, startX, startY, endX, endY;
int i, j;



void printSolution() {

    printf("Solution:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", solution[i][j]);
        }
        printf("\n");
    }
}

int solveMaze(int x, int y) {
    if (x < 0 || x >= rows || y < 0 || y >= cols) {
        return 0;
    }
    if (maze[x][y] == 0) {
        return 0;
    }
    if (x == endX && y == endY) {
        solution[x][y] = 1;
        return 1;
    }
    if (solution[x][y] == 1) {
        return 0;
    }
    solution[x][y] = 1;
    if (solveMaze(x-1, y) == 1) {
        return 1;
    }
    if (solveMaze(x+1, y) == 1) {
        return 1;
    }
    if (solveMaze(x, y-1) == 1) {
        return 1;
    }
    if (solveMaze(x, y+1) == 1) {
        return 1;
    }
    solution[x][y] = 0;
    return 0;
}

int main() {

    FILE *ptr;
    ptr=fopen("solution.txt","w+");


    printf("Enter the number of rows  of the maze: ");
    scanf("%d", &rows);
    printf("Enter the number of columns of the maze: ");
    scanf("%d", &cols);

    printf("Enter the maze (0 for blocked cell, 1 for free cell):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    printf("Enter the starting point (row and column): ");
    scanf("%d%d", &startX, &startY);

    printf("Enter the ending point (row and column): ");
    scanf("%d%d", &endX, &endY);

    if (solveMaze(startX, startY) == 1) {
        printSolution();
        fprintf(ptr, "%s", "Welcome to file containing The solution\n The solution is as follows: \n \n");
for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fprintf(ptr,"%d ", solution[i][j]);
        }
        fprintf(ptr,"\n");
    }
  fprintf(ptr, "%s","\n \n Here 1 represents free cell and 0 represent bolcked cell");
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
