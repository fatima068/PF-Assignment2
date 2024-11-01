#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void newGrid(char grid[6][5]);
void displayGrid(char grid[6][5]);
int rowSearch(char grid[6][5], char searchstr[5]);
int colSearch(char grid[6][5], char searchstr[5]);

int main()
{
    char grid[6][5], searchstr[5] =" ";
    int i, j, score = 0, found;
    newGrid(grid);

    while(1)
    {
        displayGrid(grid);
        printf("Enter string to search: ");
        scanf("%s", searchstr);
        if(strcmp(searchstr, "END")==0)
        {
            printf ("game ended\n\nNEW GRID:");
            newGrid(grid);
            displayGrid(grid);
            break;
        }

        if (strlen(searchstr) > 5)
        {
            printf("invalid input\n");
            break;
        }
        else
        {
            //SEARCH ROWS
            found = rowSearch(grid, searchstr);
            if(found == 1)
            {
                score++;
                printf ("String found, score = %d\n", score);
                continue;
            }
            else
            {
                //SEARCH COLUMNS
                found = colSearch(grid, searchstr);
                if(found == 1)
                {
                    score++;
                    printf ("String found, score = %d\n", score);
                }
                else
                {
                    score--;
                    printf ("String not found, score = %d\n", score);
                }                
            }           
        }
    }
}

void newGrid(char grid[6][5])
{
    int i,j;
    srand(time(0));
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 5; j++)
        {
            grid[i][j] = 'A' + (rand() % 26);
        }
    }
    char rollnum[] = "0924";
    strcpy(grid[5], rollnum);
    grid[5][4] = 'A' + (rand() % 26);
}

void displayGrid(char grid[6][5])
{
    int i, j;
    printf("\n");
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("  %c  ", grid[i][j]);
        }
        printf("\n\n");
    }
}

int rowSearch(char grid[6][5], char searchstr[])
{
    int i, j, k, found;
    for (i = 0; i < 5; i++)
    {
        for (int j = 0; j <= 5 - strlen(searchstr); j++)
        { 
            found=1;
            for(k=0; k<strlen(searchstr);k++)
            {
                if(searchstr[k] != grid[i][j+k])
                {
                    found=0;
                    break;
                 }
            }
            if(found==1)
            {
                for(k=0; k<strlen(searchstr); k++)
                {
                    grid[i][j+k] = ' ';
                }
                return 1;
            }              
        }
    }
    return 0;       
}

int colSearch(char grid[6][5], char searchstr[])
{
    int i, j, k, found;
    for (i = 0; i < 5; i++)
    {
        for (int j = 0; j <= 5 - strlen(searchstr); j++)
        { 
            found=1;
            for(k=0; k<strlen(searchstr);k++)
            {
                if(searchstr[k] != grid[j+k][i])
                {
                    found=0;
                    break;
                 }
            }
            if(found==1)
            {
                for(k=0; k<strlen(searchstr); k++)
                {
                    grid[j+k][i] = ' ';
                }
                return 1;
            }              
        }
    }
    return 0;       
}