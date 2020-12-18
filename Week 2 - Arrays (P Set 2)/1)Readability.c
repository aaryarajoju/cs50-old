//CS50-WEEK2-PSET2-READABILITY
//"Implement a program that computes the approximate grade level needed to comprehend some text."

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{

    //getting the text to be analyzed
    string text = get_string("Text: ");

    float letters = 0;
    float words = 0;
    float sentences = 0;

    //for loop to counting the number of letters, words and sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //counts the number of alphabets
        if (isalpha(text[i]))
        {
            letters++;
        }

        //counts the number of words
        else if (text[i] == ' ' && text[i - 1] != '.' && text[i - 1] != '!' && text[i - 1] != '?')
        {
            words++;
        }

        //counts the number of sentences
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    //total number of words
    words = words + sentences;

    //calculating the value of L and S
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;

    //calculating the readability index
    float index = round((0.0588 * L) - (0.296 * S) - 15.8);

    //printing out the class
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }

    return 0;
}
