#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text, int str_length);
int count_words(string text, int str_length);
int count_sentences(string text, int str_length);

int main(void)
{
    // prompt user
    string text = get_string("Text: ");

    // string length
    int length = strlen(text);

    int letters = count_letters(text, length);
    int words = count_words(text, length);
    int sentences = count_sentences(text, length);

    // calculation
    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentences / (float)words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded_index = round(index);

    // output result
    if (rounded_index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (rounded_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", rounded_index);
    }
}

int count_letters(string text, int str_length)
{
    int letters = 0;

    // loop for counting letters
    for (int i = 0; i < str_length; i++)
    {
        char c = text[i];
        if (isalpha(c) != 0)
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text, int str_length)
{
    int words = 0;
    bool inWord = false;

    // loop for counting words
    for (int i = 0; i < str_length; i++)
    {
        char c = text[i];
        if (isspace(c))
        {
            inWord = false;
        }
        else
        {
            if (!inWord)
            {
                words++;
                inWord = true;
            }
        }
    }

    return words;
}

int count_sentences(string text, int str_length)
{
    int sentences = 0;

    // loop for counting sentences
    for (int i = 0; i < str_length; i++)
    {
        char c = text[i];
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    return sentences;
}