//CS50-WEEK2-PSET2-CAESAR
//"Implement a program that encrypts messages using Caesar’s cipher."

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[]){

    int key = 0;
    string text = "";

    if (argc == 2) key = atoi(argv[1]);

    if (key > 26) key = key % 26;

    if (argc != 2 /*add stuff like if the key is not numeric and not over 0*/) {
        printf("Usage: ./caesar key\n");
        return 1;
    } else {
        text = get_string("plaintext: ");

        for (int i = 0, n = strlen(text); i < n; i++){
            if (text[i] >= 65 && text[i] <= 90){
                if (text[i] + key > 90)text[i] -= 26;
                text[i] += key;
            } else if (text[i] >= 97 && text[i] <= 122){
                if (text[i] + key > 122) text[i] -= 26;
                text[i] += key;
            }
        }
        printf("ciphertext: %s\n", text);
    }

    return 0;
}
