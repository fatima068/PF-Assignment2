#include <stdio.h>
int game(int n);
int main()
{
    int n;
    printf ("enter total number of matchsticks: ");
    scanf("%d", &n);
    if (game(n) == -1)
        printf ("player A cannot win");
    else
        printf ("To win, player A should pick %d matchsticks on first turn", game(n));
}

int game(int n)
{
    if (n%5==0)
        return -1;
    else
    {
        return n%5;      
    }
}