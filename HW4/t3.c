/*
Change of file

In this task, I change the location of tid=omp_get_thread_num(), because
the program seems do not understand the bracket outside for loop. So if 
I move the statement inside the loop, then the tid will get the right 
thread number without compiling error. 

*/



#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 50
#define CHUNKSIZE 5

int main(int argc, char *argv[])
{
    int i, chunk, tid; 
    float a[N], b[N], c[N];

    /* Some initializations */
    for (i = 0; i < N; i++){
        a[i] = b[i] = i * 1.0;}
    chunk = CHUNKSIZE;
    #pragma omp parallel for \
      shared(a, b, c, chunk) \
      private(tid, i)        \
      schedule(static, chunk) 

        for (i = 0; i < N; i++)
        {
            
            c[i] = a[i] + b[i];
            tid = omp_get_thread_num();
            printf("tid = %d i = %d c[i] = %f\n", tid, i, c[i]);
        }
    
    return 0;
}
