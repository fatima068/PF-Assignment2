/*Question : 8
Write a C program that contains the following functions for different numerical conversions:
1. int BinaryToDecimal(int number); Converts a binary number to its decimal equivalent.
2. int DecimalToBinary(int number); Converts a decimal number to its binary equivalent.
3. void DecimalToHexadecimal(int number); Converts a decimal number to its hexadecimal 
   equivalent and prints it.
4. void HexadecimalToDecimal(string hexNumber); Converts a hexadecimal number to its decimal equivalent and prints it.
5. void BinaryToHexadecimal(int number); Converts a binary number to its hexadecimal 
   equivalent and prints it.
6. void HexadecimalToBinary(string hexNumber); Converts a hexadecimal number to its binary equivalent and prints it.
   Each function should take an appropriate input and return or display the converted value. Ensure that the program handles invalid inputs gracefully. Your program must display the menu which function the user wants to call.*/

 #include <stdio.h>
 #include <string.h>

 int BinaryToDecimal(int number);
 int DecimalToBinary(int number);
 void DecimalToHexadecimal(int number);
 void HexadecimalToDecimal(char hexNumber[]);
 void BinaryToHexadecimal(int number);
 void HexadecimalToBinary(char hexNumber[]);

 int main()
 { 
     int choice;  
    printf("Which Operation do you want to perform? Enter numbers 1 to 6\n1. BinaryToDecimal\n2. DecimalToBinary\n3. DecimalToHexadecimal\n4. HexadecimalToDecimal\n5. BinaryToHexadecimal\n6. HexadecimalToBinary\n");
    scanf("%d", &choice);

    switch (choice)
     {
            case 1:
                printf ("enter binary number \n");
                int binary, ans;
                scanf("%d", &binary);
                ans = BinaryToDecimal (binary);
                printf ("Decimal equivalent is %d\n", ans);
                break;

        case 2:
                printf ("enter decimal number \n");
                int decimal, ans;
                scanf("%d", &decimal);
                ans =  DecimalToBinary(decimal);
                printf ("Binary equivalent is %d\n", ans);
                break;

        case 3:
                printf ("enter decimal number \n");
                int decimal;
                scanf("%d", &decimal);
                DecimalToHexadecimal (decimal);
                break;
            }

        case 4:
                printf ("enter hexadecimal number \n");
                char hexadecimal[10];
                scanf("%s", hexadecimal);
                HexadecimalToDecimal (hexadecimal);
                break;    

        case 5:            
                printf ("enter binary number \n");
                int binary;
                scanf("%d", &binary);
                BinaryToHexadecimal(binary);
                break;            

         case 6:             
                printf ("enter hexadecimal number \n");
                char hexadecimal[10];
                scanf("%s", hexadecimal);
                HexadecimalToBinary (hexadecimal);
                 break;             

        default:
            printf ("invalid input");
            break;
      }
 }


 int BinaryToDecimal(int number)
 {
     int digit, base=1, decimal=0, flag =1;

     while (number > 0 && flag == 1)
     {
         digit = number % 10;
         if (digit == 0 || digit == 1)
         {

             decimal = decimal + (digit * base);
             base = base * 2;
             number = number/10;
         }
         else 
         {
             printf ("invalid input \n");
             flag = 0;
         }
     }
     return decimal;
 }


 int DecimalToBinary(int number)
 {
     int rem, base = 10;
     int binary;
     binary = number % 2;
     number = number / 2;

     if(number <0)
         printf("invalid input. enter Positive numbers\n");

     while (number > 0)
     {
         rem= number % 2;
         number = number / 2;
         binary = binary + (rem * base);
         base = base * 10;
     }
     return binary;
 }


 void DecimalToHexadecimal(int number)
 {
     int rem, i=0;
     char hexadecimal[10];

     if(number <0)
         printf("invalid input. enter Positive numbers\n");

     while (number > 0)
     {
         rem= number % 16;
         number = number / 16;

         if (rem < 10)
         {
             hexadecimal[i] = rem + 48;
         }
         else
         {
             hexadecimal[i] = rem + 55;
         }
         i++;
     }
     printf ("Hexadecimal equivalent is ");
     for(int j = i; j>=0; j--)
     {
         printf ("%c", hexadecimal[j]);
     }
 }


 void HexadecimalToDecimal(char hexNumber[])
 {
     int decimalVal, base = 1, decimal= 0;

     for(int i=strlen(hexNumber)-1; i>=0; i--)
     {
         if(hexNumber[i] <= '9' &&  hexNumber[i] >= '0'  )         
             decimalVal = hexNumber[i] - 48;         
         else if (hexNumber[i] <= 'F' &&  hexNumber[i] >= 'A'  )  
             decimalVal = hexNumber[i] - 55;
         else if (hexNumber[i] <= 'f' &&  hexNumber[i] >= 'a'  )
             decimalVal = hexNumber[i] - 87;
         else 
             printf ("invalid input ");
         decimal = decimal + (decimalVal * base);
         base = base * 16;         
     }
     printf ("Decimal equivalent is %d", decimal);
 }


 void BinaryToHexadecimal(int number)
 {

     int decimal;
     decimal = BinaryToDecimal(number);
     DecimalToHexadecimal (decimal);
 }


 void HexadecimalToBinary(char hexNumber[])
 {
     int decimalVal, base = 1, decimal= 0 ;
     int binary;

     for(int i=strlen(hexNumber)-1; i>=0; i--)
     {
         if(hexNumber[i] <= '9' &&  hexNumber[i] >= '0'  )         
             decimalVal = hexNumber[i] - 48;         
         else if (hexNumber[i] <= 'F' &&  hexNumber[i] >= 'A'  )         
             decimalVal = hexNumber[i] - 55;        
         else if (hexNumber[i] <= 'f' &&  hexNumber[i] >= 'a'  )         
             decimalVal = hexNumber[i] - 87;         
         else         
             printf ("invalid input ");         
         decimal = decimal + (decimalVal * base);
         base = base * 16;                   
     }

     binary= DecimalToBinary(decimal);
     printf ("%d", binary);
 }