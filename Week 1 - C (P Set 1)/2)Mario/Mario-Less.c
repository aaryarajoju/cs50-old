//CS50-WEEK1-PSET1-MARIO-LESS
//"Let’s recreate that pyramid (Toward the end of World 1-1 in Nintendo’s Super Mario Brothers, Mario must ascend right-aligned pyramid of blocks) in C, albeit in text, using hashes (#) for bricks."

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    //user input for the height for the pyramid
    //do-while loop checks if the user input is between 1 and 8 (both inclusive)
    do
    {
        height = get_int("Height : ");
    }
    while (height < 1 || height > 8);

    //prints the pyramid
    for (int i = 0; i < height; i++)
    {
        //prints the spaces
        for (int j = height - 1; j > i; j--)
        {
            printf(" ");
        }

        //prints the hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        
        printf("\n");
    }
    return 0;
}
