//CS50-WEEK1-PSET1-HELLO
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);

    return 0;
}
