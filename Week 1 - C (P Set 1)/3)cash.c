//CS50-WEEK1-PSET1-CASH
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;

    do{
        change = get_float("Change Owed : ");
    }while (change < 0);

    int cents = round(100 * change);
    int coins = 0;

    while(cents > 0){
        if (cents >= 25){
            cents = cents - 25;
            coins++;
        }
        else if (cents >= 10){
            cents = cents - 10;
            coins++;
        }
        else if (cents >= 5){
            cents = cents - 5;
            coins++;
        }
        else {
            cents = cents - 1;
            coins++;
        }
    }
    printf("%d \n", coins);
    return 0;
}
