#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_digits(string stringcheck);

int main(int argc, string argv[])
{
    //Checks if the command line has only two arguments and checks if that 2nd input is only digits
    if ((argc == 2) && (only_digits(argv[1])))
    {
        //Takes the 2nd input of only digits and converts it to an integer so it can act as the key
        string cmdinput = argv[1];
        int key = atoi(cmdinput);
        //Takes the users input for the plaintext to be ciphered
        string plaintext = get_string("Enter the plaintext: ");
        int i;
        int toNumber;
        printf("ciphertext: ");
        //Loops through the plain text
        for (i = 0; i < strlen(plaintext); i ++)
        {
            //If the character is uppercase it takes away the ASCII value of 'A' so it corresponds to the correct number e.g. A=0,b=1 etc
            if (isupper(plaintext[i]))
            {
                toNumber = plaintext[i] - 'A';
                printf("%c", (((toNumber + key) % 26) + 'A'));
            }
            //Does the same but subtracts 'a' if its lowercase
            else if (islower(plaintext[i]))
            {
                toNumber = plaintext[i] - 'a';
                printf("%c", (((toNumber + key) % 26) + 'a'));
            }
            else
            {
                printf("%c", plaintext[i]);
            }

        }
        printf("\n");

        return 0;
    }
    else
    {
        //Tells the user how to use the program if their input is incorrect
        printf("Usage: ./caesar key");
        return 1;
    }

}

//Checkz that the 2nd inputted argument is only digits or not
bool only_digits(string stringcheck)
{
    int i;
    int counter = 0;
    for (i = 0; i < strlen(stringcheck); i++)
    {
        bool digitcheck = isdigit(stringcheck[i]);
        if (digitcheck)
        {
            counter += 1;
        }
    }
    if (counter == strlen(stringcheck))
    {
        return true;
    }
    else
    {
        return false;
    }
}


