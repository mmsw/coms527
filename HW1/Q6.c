#include <stdio.h>
int Factorial(int n){
    if(n == 0) return 1;
    return n * Factorial(n-1);
}
int combination(int n, int m){
    return Factorial(n) / (Factorial(m) * Factorial(n-m));
}
void print_pascals_triangle(int row)
{
    for(int i = 0; i <= row; i++) {
        for(int j = 0; j <= i; j++) printf("%d ", combination(i, j));
        printf("\n");
    }
}
int main() {
    printf("Input the row needed for printing\n");
    int row = 0;
    scanf("%d", &row);
    printf("The following is the triangle you need\n");
    print_pascals_triangle(row);
    return 0;
}


