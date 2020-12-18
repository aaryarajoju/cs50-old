//CS50-WEEK2-PSET2-SUBSTITUTION
//"Implement a program that implements a substitution cipher."

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

//initializing some var
string aphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int upperCaseStart = 65;
const int lowerCaseStart = 97;
const int upperCaseEnd = 90;
const int lowerCaseEnd = 122;

//function that checks if the key has any repeating chars
int repeats(string key)
{
    int count = 0;

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (aphabets[i] == toupper(key[j]))
            {
                count++;
            }
            if (count > 1)
            {
                return 1;
            }
        }
        count = 0;
    }
    return 0;
}

//function to check if the key consists of only alphabets
int isApha(string key)
{

    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            return 0;
        }
    }
    return 1;
}

//function to encode the text and print it
void encodeText(string strtxt, string key)
{

    int position;

    for (int i = 0; i < strlen(strtxt); i++)
    {

        if (strtxt[i] <= upperCaseEnd)
        {
            position = strtxt[i] - upperCaseStart;
        }
        else
        {
            position = strtxt[i] - lowerCaseStart;
        }

        if (strtxt[i] <= upperCaseEnd && strtxt[i] >= upperCaseStart)
        {
            printf("%c", toupper(key[position]));
        }
        else if (strtxt[i] <= lowerCaseEnd && strtxt[i] >= lowerCaseStart)
        {
            printf("%c", tolower(key[position]));
        }
        else
        {
            printf("%c", strtxt[i]);
        }
    }

}

int main(int argc, string argv[])
{

    string key = "";
    int map[26];
    string code = argv[1];
    string text;

    //checking the number of args and len of key
    if (argc == 2 && strlen(code) == 26)
    {
        key = code;
    }

    //validating the number of args
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // validating the len of key
    else if (strlen(code) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //validating if the key has only aphabets
    else if (!isApha(key))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    //validating if the key has any repeating chars
    else if (repeats(key))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    //calling the encodetext function to return the encoded text
    else
    {
        text = get_string("plaintext: ");
        printf("ciphertext: ");
        encodeText(text, key);
        printf("\n");
    }

    return 0;
}
