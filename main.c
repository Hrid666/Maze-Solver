#include<stdio.h>
#include<ctype.h>
#define MAX 10

int maze[MAX][MAX], solution[MAX][MAX];
int n;

void printSolution()
{
    printf("\nSolved Maze Path:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(solution[i][j]==1)
                printf("*");
            else if(maze[i][j]==1)
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

int isSafe(int x, int y)
{
    return (x >=0 && x<n &&
            y >=0 && y<n &&
            maze[x][y]==0 &&
            solution[x][y]==0);

}

int solveMaze(int x, int y, int endX, int endY)
{
    if(x==endX && y==endY)
    {
        solution[x][y] = 1;
        return 1;

    }

    if(isSafe(x,y))
    {
        solution[x][y] = 1;

        if(solveMaze(x,y+1,endX, endY)) return 1;
        if(solveMaze(x+1,y,endX, endY)) return 1;
        if(solveMaze(x,y-1,endX, endY)) return 1;
        if(solveMaze(x-1,y,endX, endY)) return 1;

        solution[x][y] = 0;
        return 0;
    }

    return 0;
}

void clearSolution()
{
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
           solution[i][j]=0;
}


int main() {
    char playAgain = 'Y';

    while (toupper(playAgain) == 'Y') {
        int startX, startY, endX, endY;

        printf("\nEnter size of the maze (max %d): ", MAX);
        scanf("%d", &n);

        printf("Enter maze matrix (%d x %d, 0 = path, 1 = wall):\n", n, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                scanf("%d", &maze[i][j]);
                solution[i][j] = 0;
            }

        printf("Enter start coordinates (x y): ");
        scanf("%d %d", &startX, &startY);

        printf("Enter end coordinates (x y): ");
        scanf("%d %d", &endX, &endY);

        if (!isSafe(startX, startY) || !isSafe(endX, endY)) {
            printf("\nStart or End is on a wall or outside the maze!\n");
        } else if (solveMaze(startX, startY, endX, endY)) {
            printSolution();
        } else {
            printf("\nNo path found!\n");
        }
        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);

        if (toupper(playAgain) == 'N') {
            char confirmExit;
            printf("Are you sure you want to exit? (Y/N): ");
            scanf(" %c", &confirmExit);

            if (toupper(confirmExit) == 'Y') {
                printf("Please play!!\n");
                printf("Do you want to continue playing? (Y/N): ");
                scanf(" %c", &playAgain);

                if (toupper(playAgain) == 'N') {
                    printf("\nThank you for playing!! Hope you enjoyed it \n");

                    int rating;
                    do {
                        printf("Please rate the game on a scale of 1 to 5: ");
                        scanf("%d", &rating);
                    } while (rating < 1 || rating > 5);

                    printf("\nYou rated this game: %d/5\n", rating);
                    break;
                }
            }
        }

        clearSolution();
    }

    printf("\nDeveloped by Hridoyaja Deb\n");
    printf("Email: hridoyajadeb@gmail.com\n");

    return 0;
}
