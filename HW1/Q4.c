#include <stdio.h>
#include <math.h>

int isArmstrongs(int number)
{
    int orig = number;
    int degree = log10(number) + 1;
    int check = 0;
    while(number != 0){
        check += pow(number % 10, degree);
        number = number / 10;
    }
    return (orig == check);
}

int main() {
    printf("The following are Armstrong number within 10000000:\n");
    for(int i = 0; i < 10000000; i++){
        if(isArmstrongs(i) == 1){
            printf("%d\n", i);
        }
    }
    return 0;
}