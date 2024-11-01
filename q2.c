#include <stdio.h>
#include <string.h>
void wordfrequency(char word[], int wordfreq[]);
int main() 
{
    char userin[100], word[30];
    int sloganfreq[256] = {0}; 
    int i = 0, k;

    printf("Enter a string: ");
    fgets(userin, sizeof(userin), stdin);

    while (userin[i] != '\0') 
    {
        k = 0;
        while (userin[i] != ' ' && userin[i] != '\0')
         {
            word[k++] = userin[i++];
         }
        word[k] = '\0'; 

        while (userin[i] == ' ') 
        {
            i++;
        }

        if (strlen(word) > 0) 
        {
            printf("\nWord: %s\n", word);
            wordfrequency(word, sloganfreq); 
        }
    }

    for (i = 0; i < 256; i++) 
    {
        if (sloganfreq[i] > 0) 
        {
            printf("'%c': %d, ", i, sloganfreq[i]);
        }
    }
}

void wordfrequency(char word[], int wordfreq[]) 
{
    int charFound[256] = {0}; 
    int len = strlen(word);

    for (int i = 0; i < len; i++) 
    {
        if (word[i] != ' ' && word[i] != '\0') 
        {
            charFound[(int)word[i]] = 1;
        }
    }
    for (int i = 0; i < 256; i++) 
    {
        if (charFound[i]) 
        {
            wordfreq[i]++;
        }
    }
}