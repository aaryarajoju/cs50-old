//CS50-WEEK1-PSET1-CREDIT
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Getting the card number from the user
    long card = get_long("Enter card number: ");

    long num = card;
    int digits = 0;

    //checking the number of digits in the card number
    while (num > 0)
    {
        digits++;
        num = num / 10;
    }

    int name;

    //checks if the number of digits are one of the only three values given
    if (digits == 13 || digits == 15 || digits == 16)
    {

        bool isCardValid = false;
        int sum = 0;
        long tempCard = card;

        //CheckSum using the Luhn's Algorithm
        /*"Most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:
           1) Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
           2) Add the sum to the sum of the digits that weren’t multiplied by 2.
           3) If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!"*/
        do
        {
            //the first card from right gets added to sum
            sum += tempCard % 10;
            //the first number from the right is eliminated
            tempCard = tempCard / 10;

            if (tempCard % 10 < 5)
            {
                //twice the alternate card from right gets added to s
                sum += 2 * (tempCard % 10);
                //the first number from the right is eliminated
                tempCard = tempCard / 10;
            }
            else
            {
                //twice the alternate card from right gets added to sum
                sum += ((2 * (tempCard % 10)) % 10) + 1;
                //the first number from the right is eliminated
                tempCard = tempCard / 10;
            }

        }
        while (tempCard > 0);

        //checking if the Luhn's Algorithm is satisfied
        if (sum % 10 == 0)
        {
            isCardValid = true;
        }

        //Checking the type of card, if the Luhn's Algorithm is satisfied
        if (isCardValid)
        {

            //for checking the first digit in the card number
            long first = card;
            while (first > 10)
            {
                first = first / 10;
            }

            //for checking the first two digits in the card number
            long firstTwo = card;
            while (firstTwo > 100)
            {
                firstTwo = firstTwo / 10;
            }

            //checking the type of the card based on the information provided
            /*"American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers"*/
            /*"All American Express numbers start with 34 or 37;
            most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem);
            and all Visa numbers start with 4."*/

            //AMEX cards will have 15 digits and will start with a 34 or a 37
            if (digits == 15 && (firstTwo == 34 || firstTwo == 37))
            {
                name = 1;
            }

            //MASTERCARD cards will have 16 digits starting with a 51 or 52 or 53 or 54 or 55
            else if (digits == 16 && (firstTwo == 51 || firstTwo == 52 || firstTwo == 53 || firstTwo == 54 || firstTwo == 55))
            {
                name = 2;
            }

            //VISA cards will have 13 or 16 digits and will start with a 4
            else if ((digits == 13 || digits == 16) && first == 4)
            {
                name = 3;
            }

            //if none of the cases are satisfied, the card is invalid
            else
            {
                name = 4;
            }
        }

        //if none of the cases are satisfied, the card is invalid
        else
        {
            name = 4;
        }
    }

    //if none of the cases are satisfied, the card is invalid
    else
    {
        name = 4;
    }

    //Switch-Case for printing out the tyoe of the card
    switch (name)
    {
        case 1 :
            printf("AMEX\n");
            break;

        case 2 :
            printf("MASTERCARD\n");
            break;

        case 3 :
            printf("VISA\n");
            break;

        case 4 :
            printf("INVALID\n");
            break;
    }
    return 0;
}
