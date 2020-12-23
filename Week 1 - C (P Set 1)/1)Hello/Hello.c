//CS50-WEEK1-PSET1-HELLO
//"Modify the Hello World program in such a way that it first prompts the user for their name and then prints 'hello, so-and-so', where 'so-and-so' is their actual name."

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //user input for user's name
    string name = get_string("What is your name?\n");
    //prints a personalized hello
    printf("hello, %s\n", name);

    return 0;
}
