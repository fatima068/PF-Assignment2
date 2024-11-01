//ASSIGNMENT Q1

#include <stdio.h>
int main()
{
    int userin = 10000, i, smallest, secondsmall;
    int arr[5];

    for (i=0; i<5; i++)
    {
        while (userin >= 9999)
        {
            printf ("enter number less than 9999: ");
            scanf("%d", &userin);
        }
        arr[i] = userin; 
        userin = 10000;
    }

    smallest = 9999;
    secondsmall = 9999;

    for (i=0; i<5; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    for (i=0; i<5; i++)
    {
        if (arr[i] < secondsmall && arr[i] > smallest)
        {
            secondsmall = arr[i];
        }
    }

    printf ("second smallest number in the array is %d", secondsmall);
}