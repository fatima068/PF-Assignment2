#include <stdio.h>

void horizontalHistogram(int values[], int count);
void verticalHistogram(int values[], int count);
int inputHandling(int values[]);

int main()
{
    int values[20], count;
    count = inputHandling(values);
    horizontalHistogram(values, count);
    verticalHistogram(values, count); 
}

int inputHandling(int values[])
{
    int count;
    printf ("enter total number of values for histogram: ");
    scanf("%d", &count);
    for (int i=0; i<count; i++)
    {
        printf ("enter value %d: ", i+1);
        scanf("%d", &values[i]);
    }
    return count;
}


void horizontalHistogram(int values[], int count)
{
    printf("HORIZONTAL HISTOGRAM:\n");
    for(int i =1; i <= count; i++)
    {    
        printf("value %d: ",i);
        for (int j =1; j<=values[i-1]; j++)
        {
            printf("*");
        }
        printf ("\n");
    }
}


void verticalHistogram(int values[], int count)
{
    printf ("\nVERTICAL HISTOGRAM: \n");
    int largest = - 999, i, j, x, y, spaces, asterik;
    for (int i=0; i<count; i++)
    {
        if (values[i] > largest)
        largest = values[i];
    }

    char arr[20][20]= {};
    int k =largest;

    for(j=0; j<count; j++)
    {
        spaces = largest - values[j];
        asterik = largest - spaces;

            for(x=0; x<spaces; x++)
            {
                arr[x][j] = ' ';
            }

            for (y=x; y<largest; y++)
            {
                arr[y][j] = '*';
            }
    }

    for (int a =0; a < largest; a++)
    {
        for(int j =0; j <count; j++)
        {
            printf ("%c", arr[a][j]);
        }
        printf ("\n");
    }
}