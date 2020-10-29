//CS50-WEEK1-PSET1-CASH
/*"When making change, odds are you want to minimize the number of coins you’re dispensing for each customer, lest you run out (or annoy the customer!).
Fortunately, computer science has given cashiers everywhere ways to minimize numbers of coins due: greedy algorithms."
"Suppose that a cashier owes a customer some change and in that cashier’s drawer are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
The problem to be solved is to decide which coins and how many of each to hand to the customer.
Think of a “greedy” cashier as one who wants to take the biggest bite out of this problem as possible with each coin they take out of the drawer."*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;

    //user input for the amount of change in dollars
    //do-while loop checks that the amount entered is non-negative
    do
    {
        change = get_float("Change Owed : ");
    }
    while (change < 0);

    //converting the user input of change in dollars to change in cents
    int cents = round(100 * change);

    int coins = 0;

    //while loop will run till the all of the change is covered
    while (cents > 0)
    {

        //checks if there is a possibility to cover the change with a quarter($0.25)
        //then checks how many quarters would be needed
        if (cents >= 25)
        {
            cents = cents - 25;
            coins++;
        }

        //checks if there is a possibility to cover the change with a dime($0.10)
        //then checks how many dimes would be needed
        else if (cents >= 10)
        {
            cents = cents - 10;
            coins++;
        }

        //checks if there is a possibility to cover the change with a nickle($0.05)
        //then checks how many nickles would be needed
        else if (cents >= 5)
        {
            cents = cents - 5;
            coins++;
        }

        //checks how many pennies($0.01) are required to cover the rest of the change
        else
        {
            cents = cents - 1;
            coins++;
        }
    }

    //prints the total number of coins required
    printf("%d \n", coins);

    return 0;
}
