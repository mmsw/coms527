#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>


int main()
{
    long int length;
    long int start, end;
    printf("Please input length of matrix\n");
    scanf("%ld", &length);
    int* matrix1 = (int*)malloc(4 * length);
    int* matrix2 = (int*)malloc(4 * length);
    int* sum = (int*)malloc(4 * length);
    
    srand(time(NULL));
    for(int i = 0; i < length; i++)
    {
        matrix1[i] = rand();
        matrix2[i] = rand();
        //printf("matrix is %d", matrix1[i]);
    }
    start = time(NULL);
    #pragma omp target
    {
        #pragma omp parellel for
        for(int i = 0; i < length; i++)
        {
            sum[i] = matrix1[i] + matrix2[i];
            //printf("Num is %d\n", sum[i]);
        }
    }
    end = time(NULL);
    long int time1 = end - start;
    long int sum0 = 0;
    start = time(NULL);
    #pragma omp target
    {
        #pragma omp parellel for 
        for(int i = 0; i < length; i++)
        {
            sum0 += sum[i];
            //printf("Sum until now is %ld\n", sum0);
            
        }
    }
    end = time(NULL);
    printf("Running time for sum is \t %ld seconds\n", time1);
    printf("Running time for multification is \t %ld seconds\n", end - start);
    return 0;
}


