/*Compress a Word: Write a function that takes a string (a word) as input and returns a minimized version of the word, where all consecutive duplicate letters are reduced to one.

Multiple Word Compression: You will then apply this function to a list of words and return the minimized version for each word.

Add a feature to calculate how many characters were removed during the compression process.

Input: words = [“booooook”, “coooool”, “heeeey”]
Output: [“bok”, “col”, “hey”]*/

# include <stdio.h>
# include <string.h>

void compression(char userin[]);

int main ()
{
    int choice, num, i;
    char x[30], y[20][30];
    printf ("Select option 1 or 2:\n1. Compress one word\n2. Compress a list of words\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf ("enter word to compress: ");
            scanf("%s", x);
            compression(x);
            break;

        case 2:
            printf("enter number of words to be compressed: ");
            scanf ("%d", &num);

            if (num > 20)
            {
                printf("Maximum of 20 words allowed.\n");
                return 1;
            }

            for (i = 0; i < num; i++)
            {
                printf("Enter word %d: ", i + 1);
                scanf("%s", y[i]);
                compression (y[i]);
            }
            break;

        default:
            printf("invalid input");
            break;
    }
}


void compression(char userin[])
{
    int i, j, k=0, removed = 0;
    char output[30];

    //REMOVING DUPLICATE CHARACTERS
    for (i=0; i<strlen(userin); i++)
    {
        for (j=i+1; j<strlen(userin); j++)
        {
            if (userin[i] == userin[j] && userin[j] != ' ')
            {
                userin[j] = '0';
            }
            else 
                break;
        }
    }

    //COUNT OF CHARACTERS REMOVED
    for (i=0; i<strlen(userin); i++)
    {
        if((userin[i] >= 'a' && userin[i] <= 'z') || (userin[i] >= 'A' && userin[i] <= 'Z'))
        {
            output[k] = userin[i];
            k++;
        }
        else
        {
            removed++;
            continue;
        }
        output[k] = '\0';
    }

    printf("Compressed string: %s\nNumber of removed characters: %d\n\n", output, removed);
}