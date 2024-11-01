# TODO
from cs50 import get_string

# Takes users input using get_string from the cs50 python library
text = get_string('Text:   ')


def count_letters(text):
    letters = 0
    for i in range(len(text)):
        if text[i].isalnum() == True:
            letters += 1
    return letters


def count_words(text):
    words = 1
    for i in range(len(text)):
        if text[i] == ' ':
            words += 1
    return words


def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        if text[i] == '!' or text[i] == '?' or text[i] == '.':
            sentences += 1
    return sentences


# Calculating the number of letters and words and sentences by calling the functions that are defined above
numOfLetters = count_letters(text)
numOfWords = count_words(text)
numOfSentences = count_sentences(text)
# Coleman-Liau Index Formula
L = (numOfLetters / numOfWords) * 100
S = (numOfSentences / numOfWords) * 100
index = 0.0588 * L - 0.296 * S - 15.8
grade = round(index)

# Grade outputting
if grade >= 16:
    print('Grade 16+\n')
elif grade < 1:
    print('Before Grade 1\n')
else:
    print('Grade', grade, '\n')