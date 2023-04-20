all: T1 T2_with_print T2_without_print

T1: T1.c
	gcc T1.c -o T1 -fopenmp

T2_with_print: T2_with_print.c
	gcc T2_with_print.c -o T2_with_print -fopenmp

T2_without_print: T2_without_print.c
	gcc T2_without_print.c -o T2_without_print -fopenmp

clean: 
	rm -rf T1 T2_with_print T2_without_print