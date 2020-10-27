//CS50-WEEK1-PSET1-CREDIT
/*
TO-DO:

1) Input card number
2) checksum
3) check for card length and starting digit
4) print AMEX, VISA, MASTERCARD or INVALID


Checksum:
    (sum of alternate digits)*2 + (sum of other set of alternate digits) -> ends in 0


AMEX:
    15 digits, starts with a 34 or 37

MASTERCARD:
    16 digits, starts with a 51, 52, 53, 54 or 55

VISA:
    13 or 16 digits, starts with a 4
*/






#include <stdio.h>
#include <cs50.h>

int main(void)
{

//inut card no
    long card = get_long("Enter card number: ");

//checksum




//check for card length ands starting digits
    long num = card;
    int digits = 0;

    while (num>0){
        digits++;
        num = num/10;
    }

    long first = card;
    while (first > 10){
        first = first/10;
    }

    long firstTwo = card;
    while (firstTwo > 100){
        firstTwo = firstTwo/10;
    }

    int name;

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


//print the card type
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
