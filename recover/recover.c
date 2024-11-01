#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
//Check if only 2 command line arguments are provided
    if (argc != 2)
    {
        printf("Incorrect usage: ./recover card.raw \n");
        return 1;
    }
//Opens the file
    FILE *file = fopen(argv[1], "r");
//Checks if the file is valid and can be opened
    if (file == NULL)
    {
        printf("Error could not open file \n");
        return 1;
    }
//Initialises important identifiers
    FILE  *img = NULL;
    char *filename = malloc(8 * sizeof(char));
    int counter = 0;
    BYTE buffer[512];
//Reads to the buffer 512 bytes from the input file
    while (fread(buffer, sizeof(char), 512, file) != 0)
    {
//Checks for .jpeg header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If it's not the first header it closes the filem of the previous .jpg
            if (img != NULL)
            {
                fclose(img);
            }
            //Then defines what the name of the new file will be and increments the counter so each file will be named an increasing number
            //And then opens the file for the new jpg to be entered into
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            counter++;
        }
        //Then again if the output file is accessible it then writes 512 bytes in one chunk into the file
        if (img != NULL)
        {
            fwrite(buffer, 512, 1, img);
        }
    }
    //Closes files and frees all memory
    free(filename);
    fclose(img);
    fclose(file);
    return 0;
}