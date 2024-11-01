#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int main(void)
{
    //Asks the user for input
    //Then calls the functions to get the number of letters, words and sentences in the text.
    string text = get_string("Text: ");
    int numOfLetters = count_letters(text);
    int numOfWords = count_words(text);
    int numOfSentences = count_sentences(text);
    //Coleman-Liau Index formula
    int L = (numOfLetters / (double) numOfWords) * 100;
    int S = (numOfSentences / (double) numOfWords) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    double grade = round(index);
    //Outputs grade
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int) grade);
    }
}

int count_letters(string text)
{
    int letters = 0;
    int i;
    //Loops through every character in the text
    for (i = 0; i < strlen(text); i++)
    {
        //Checks if the char is in the alphabet to know that its a letter
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        //Checks if the char is an empty space to know that its the end of a word
        if (isspace(text[i]))
        {
            words += 1;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        //Checks if the char is a ! ? or . to indicate the end of a sentence
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences += 1;
        }
    }
    return sentences;
}