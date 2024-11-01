#include <stdio.h>

void displayGrid(char grid[5][5]);

int main ()
{
    char direction= ' ';
    int iP = 4, jP = 4;
    char grid[5][5] = 
    {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };
    displayGrid(grid);

    while(direction!= 'q' && direction != 'Q')
    {
        printf("\nEnter A to move left, D to move right, W to move up, S to move down, Q to quit the game: ");
        scanf(" %c", & direction);
        switch (direction)
        {
            case 'a':
            case 'A':
                if(jP == 0)
                    printf ("Cannot move to the left, grid does not exist\n");
                else if(grid[iP][jP-1] == 'X')
                    printf ("Obstacle encountered. Cannot move left\n");
                else
                    {
                        grid[iP][jP] = ' ';
                        jP--;
                        grid[iP][jP] = 'P';
                    }
                displayGrid(grid);
                break;


            case 'w':
            case 'W':
                if(iP == 0)
                    printf ("Cannot move up, grid does not exist\n");
                else if(grid[iP-1][jP] == 'X')
                    printf ("Obstacle encountered. Cannot move up\n");
                else
                    {
                        grid[iP][jP] = ' ';
                        iP--;
                        grid[iP][jP] = 'P';
                    }
                displayGrid(grid);
                break;


            case 's':
            case 'S':
                if(iP == 4)
                    printf ("Cannot move down, grid does not exist\n");
                else if(grid[iP+1][jP] == 'X')
                    printf ("Obstacle encountered. Cannot move down\n");
                else
                    {
                        grid[iP][jP] = ' ';
                        iP++;
                        grid[iP][jP] = 'P';
                    }
                displayGrid(grid);
                break;


            case 'd':
            case 'D':
                if(jP == 4)
                    printf ("Cannot move to the right, grid does not exist\n");
                else if(grid[iP][jP+1] == 'X')
                    printf ("Obstacle encountered. Cannot move right\n");
                else
                    {
                        grid[iP][jP] = ' ';
                        jP++;
                        grid[iP][jP] = 'P';
                    }
                displayGrid(grid);
                break;

            case 'q':
            case 'Q':
                printf("Game ended");
                break;    

            default:
                printf ("invalid input");
                break;
        }
    }
}

void displayGrid(char grid[5][5])
{
    int i, j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            printf (" '%c' ", grid[i][j]);
        }
        printf ("\n");
    }
}