
/* 
Change of file

In this one, I change the function fib() with omp task and indicate 
shared n in the function main() in order to parallelly running program.



*/





#include <stdio.h>
#include <omp.h>


int fib(int n)
{
  int x, y;
  if (n < 2) 
	  return n;
  #pragma omp task shared(x)
  x = fib(n - 1);
  #pragma omp task shared(y) 
  y = fib(n - 2);
  #pragma omp taskwait
  return x+y;

}


int main()
{
  int n,fibonacci;
  double starttime;
  printf("Please insert n, to calculate fib(n): \n");
  scanf("%d",&n);
  starttime=omp_get_wtime();
  omp_set_num_threads(16);
  #pragma omp parallel shared(n)
  {
  fibonacci=fib(n);
  }

  printf("fib(%d)=%d \n",n,fibonacci);
  printf("calculation took %lf sec\n",omp_get_wtime()-starttime);
  return 0;
}
