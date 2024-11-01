#include <stdio.h>
#include <string.h>

int main()
{
        char userin[20][20], sort[20][20], tempChar, temp[20];
        int total, i, j, length, next = 1;

        //TAKING INPUT
        printf("how many items do u want to enter? ");
        scanf("%d", &total);
        if (total>20)
            printf ("enter 20 or less words");
        else 
        {
            printf("enter your list of elements \n");
            for(i=0; i<total; i++)
            {
                scanf("%s", userin[i]);
                strcpy(sort[i], userin[i]);  
            }
        }

        //SORTING STRINGS IN SECOND ARRAY IN ALPHABETICAL ORDER
        for(int k=0; k<total; k++)
        {            
            length=strlen(sort[k]);
        for (int i = 0; i < length - 1; i++)
        {
            for (int j = i + 1; j < length; j++)
             {
                 if (sort[k][i] > sort[k][j])
                 {
                    tempChar = sort[k][i];
                    sort[k][i] = sort[k][j];
                    sort[k][j] = tempChar;
                  }
              }
          }
        }


    //GROUPING SAME TRANSACTIONS TOGETHER
    for (i=0; i<total-1; i++)
    {
        for(j=i+1; j<total; j++)
        {
            if(strcmp(sort[i], sort[j]) == 0 )
            {
                strcpy(temp, sort[i+1]);
                strcpy(sort[i+1], sort[j]);
                strcpy(sort[j], temp);
                strcpy(temp, userin[i+1]);
                strcpy(userin[i+1], userin[j]);
                strcpy(userin[j], temp);
                i++;
            }
        }
    }  

    //PRINTING GROUPED TRANSACTIONS TOGETHER
    printf("\nSorted list of group transactions:\n");
    for (i = 0; i < total; i++) 
    {
        printf ("[%s", userin[i]);
        for(j=i+1; j<total  && strcmp(sort[i], sort[j]) == 0; j++)
        {
             printf(", %s", userin[j]);   
        }    
        i =j - 1;
        printf ("] ");  
    }
}