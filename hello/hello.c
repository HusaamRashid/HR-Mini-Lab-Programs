#include <stdio.h>
//Imports library standard input outputs
#include <cs50.h>
//Imports library cs50, allows us to use get_string

int main(void)
{
    string name = get_string("What's your name?: ");
    //takes an input from the user and assigns it as a string
    printf("hello, %s\n", name);
    //outputs hello followed by the priorly inputted name
    //%s acts as a placeholder for a string which is passed in with the variable name after the comma.
}