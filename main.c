#include <stdio.h>
#include <stdlib.h>
#include <myconio.h>
#include <ctype.h>
#include <string.h>

#define TRUE            1
#define FALSE           0
#define CONSOLE_WIDTH   120  // default 80
#define CONSOLE_HEIGHT  30  // default 25
#define DIM_TEXT        30  // max limit
#define DIM_KEY         20  // max limit

int main(int argc, char *argv[])
{    
    char play;
    char inputText[DIM_TEXT];
    char secretKey[DIM_KEY];
    char encryptedText[DIM_TEXT];
    char decryptedText[DIM_KEY];
    int i, j, k, errors;

    do
    {
        clrscr();

        // init returned line 
        unsigned int returnLine = 16;
        errors = i = j = k = 0;

        // Display of additional information
        gotoxy(1, 1);
        printf("HELHa");

        gotoxy((CONSOLE_WIDTH - 10), 1);
        printf("Montignies");

        gotoxy((CONSOLE_WIDTH - 20) / 2, 5);
        printf("CRYPTAGE DE VIGENERE");

        // Request essential information
        gotoxy((CONSOLE_WIDTH - DIM_TEXT) / 2, 7);
        printf("Message : ");
        scanf("%s", &inputText);
    
        gotoxy((CONSOLE_WIDTH - DIM_KEY) / 2, 9);
        printf("Cle : ");
        scanf("%s", &secretKey);

        // Loading time
        for(int i = 0; i < 60; i++)
        {
            gotoxy(((CONSOLE_WIDTH - 60) / 2) + (i + 1), 11);
            printf("=");
            Sleep(25);
        }

        // Display the encrypted message
        gotoxy((CONSOLE_WIDTH - DIM_TEXT) / 2, 13);
        printf("Message crypte : ");
        for (int i = 0; i < inputText[i] != '\0'; i++)
        {
            if (tolower(inputText[i]) < 'a' || tolower(inputText[i]) > 'z') 
            {
                errors++;
            }
            else
            {
                if (secretKey[j] == '\0') 
                {
                    j = 0;
                }
                
                encryptedText[k] = inputText[i] + secretKey[j];
                k++; j++;
            }
        }
        encryptedText[k] = '\0';
        printf("%s", encryptedText);
        
        // Display the number of errors
        gotoxy((CONSOLE_WIDTH - DIM_TEXT) / 2, 14);
        printf("Erreur(s) : ");
        printf("%d", errors);
        
        // Display the ASCII code of the crypted text
        gotoxy((CONSOLE_WIDTH - 20) / 2, returnLine);
        for (i = 0; encryptedText[i] != '\0'; i++)
        {
            /* 5 codes maximum par ligne */
            if (!(i % 5))
            {
                returnLine++;
            }
            
            gotoxy((CONSOLE_WIDTH - 20) / 2, returnLine);
            printf("%u", encryptedText[i]);
        }
        
        // OLD CODE
        // for (int i = 0; i < strlen(inputText); i++)
        // {
        //     printf("%d ", inputText[i] + secretKey[i]);
            
        //     if ((i + 1) % 5 == 0)
        //     {
        //         printf("\n");
        //         returnLine += 1;
        //         gotoxy((CONSOLE_WIDTH - 20) / 2, returnLine);
        //     }
        // }

        // Display the crypted message
        gotoxy((CONSOLE_WIDTH - DIM_TEXT) / 2, returnLine + 2);
        printf("Message decrypte : ");
        j = 0;
        for (i = 0; encryptedText[i] != '\0'; i++)
        {
            if(secretKey[j] == '\0')
            {
                j=0;
            }            
            
            decryptedText[i] = encryptedText[i] - secretKey[j];
            j++;
        }
        decryptedText[i] = '\0';
        printf("%s", decryptedText);
        // OLD CODE
        // for (int i = 0; i < strlen(inputText); i++)
        // {
        //     decryptedText[i] = (encryptedText[i] - secretKey[i]);
        //     printf("%c", decryptedText[i]);
        // }

        // Ask if we want to play again
        gotoxy((CONSOLE_WIDTH - 20) / 2, (CONSOLE_HEIGHT - 2));
        printf("Recommencer (o/n) ? ");
        fflush(stdin);
        scanf("%c", &play);
    }
    while (tolower(play) == 'o');

    // getch();
    return 0;
}