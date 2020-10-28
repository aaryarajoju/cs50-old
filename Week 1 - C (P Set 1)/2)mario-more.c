//CS50-WEEK1-PSET1-MARIO-MORE
#include <cs50.h>
#include <stdio.h>

int main(void){

    int height;
    
    do{
        height = get_int("Height : ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++){
        for (int j = height - 1; j > i; j--){
            printf(" ");
        }
        for (int j = 0; j <= i; j++){
            printf("#");
        }
        printf(" ");
        for (int j = 0; j <= i; j++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
