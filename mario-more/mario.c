#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    //asks for input height and then checks if the value input is valid
    do
    {
        height = get_int("Enter Height between 1 and 8: ");
    }
    while ((height <= 0) || (height > 8));
    int rownum, spaces, hashnum;
    for(rownum=1;rownum<=height;rownum++)
    {
        //calculates number of spaces needed by taking the height and taking away what row we are on then prints thi
        for(spaces=1;spaces<=(height-rownum);spaces++)
        {
            printf(" ");
        }
        //calculates the number of hashes needed by doing the height take away the already calculated number of spaces and then prints them
        for(hashnum=0;hashnum<=(height-spaces);hashnum++)
        {
            printf("#");
        }
        //Adds the middle gap
        printf("  ");
        //Then adds in the hashes again to create the symmetry
        for(hashnum=0;hashnum<=(height-spaces);hashnum++)
        {
            printf("#");
        }
        //This then tells the program to create a new line so that pyramid has a structure
        printf("\n");

    }

}
