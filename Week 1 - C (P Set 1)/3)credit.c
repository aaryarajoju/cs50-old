//CS50-WEEK1-PSET1-CREDIT
#include <stdio.h>
#include <cs50.h>

int main(void)
{

    long card = get_long("Enter card number: ");

    long num = card;
    int digits = 0;

    while (num>0){
        digits++;
        num = num/10;
    }

    int name;

    if(digits == 13 || digits == 15 || digits == 16){

        bool isCardValid = false;
        int sum = 0;
        long tempCard = card;

        do {

            sum += tempCard%10;
            tempCard = tempCard/10;

            if (tempCard%10 < 5){
            sum += 2*(tempCard%10);
            tempCard = tempCard/10;
            }
            else {
               sum += ((2*(tempCard%10))%10)+1;
               tempCard = tempCard/10;
            }

        } while(tempCard > 0);

        if (sum%10 == 0){
            isCardValid = true;
        }

        if(isCardValid){

            long first = card;
            while (first > 10){
                first = first/10;
            }

            long firstTwo = card;
            while (firstTwo > 100){
                firstTwo = firstTwo/10;
            }

            if(digits == 15 && (firstTwo == 34|| firstTwo == 37)){
                name = 1;
            }
            else if(digits == 16 && (firstTwo == 51|| firstTwo == 52|| firstTwo == 53|| firstTwo == 54|| firstTwo == 55)){
                name = 2;
            }
            else if((digits == 13|| digits == 16) && first == 4){
                name = 3;
            }
            else {
                name = 4;
            }
        }
        else {
            name = 4;
        }
    }
    else{
        name = 4;
    }

    switch(name){
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
