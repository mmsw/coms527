#include <stdio.h>
#include <omp.h>
#include <time.h>
int main()
{
    long int start = time(NULL);
    int omp_num;
    #pragma omp target 
    {
        #pragma omp parallel for collapse(2)
        for(int i = 0; i < 1000000; i++)
        {
            for (int j = 0; j < 2000000; j++)
            {
                omp_num = omp_get_thread_num();
                //printf("tid = %d\n", omp_get_thread_num());
            }
        }
    }
    long int end = time(NULL);
    printf("Running time is %ld\n", end - start);
    
}
