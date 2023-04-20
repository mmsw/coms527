#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
struct timeval tval_before, tval_after, tval_result;
void init_random_array(int a[], int b[], long int length)
{
    int i = 0;
    srand(time(NULL));
    for(i = 0; i < length; i++){
        a[i] = rand();
        b[i] = rand();
    }
}

long int sequential_add(int a[], int b[], long int length)
{
    int* c = (int *)malloc(length*4);
    gettimeofday(&tval_before, NULL);
    for (int i = 0; i < length; i++)
    {
        c[i] = a[i] + b[i];
    }
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);
    return (long int)tval_result.tv_usec;
}

long int parallel_add(int a[], int b[], long int length)
{
    int* c = (int *)malloc(length*4);
    struct timeval tval_before, tval_after, tval_result;
    gettimeofday(&tval_before, NULL);
    #pragma omp parallel for
    for (int i = 0; i < length; i++)
    {
        c[i] = a[i] + b[i];
    }
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);
    return (long int)tval_result.tv_usec;
}

void exe(long int length){
    int* a = (int *)malloc(length*4);
    int* b = (int *)malloc(length*4);
    init_random_array(a, b, length);
    printf("Iteration %ld times\n", length);
    long int stime = sequential_add(a, b, length);
    long int ptime = parallel_add(a, b, length);
    printf("Seqential runtime %06ld milliseconds\n", stime);
    printf("Parallel  runtime %06ld milliseconds\n", ptime);
    printf("Speedup %06ld milliseconds\n\n", stime - ptime);
}

int main(){
    long int length;
    for(int i = 2; i < 9; i++){
        length = (long int)pow(10, (double)i);
        exe(length);
    }
}
