
#include "stdafx.h"
#include <iostream>
#include <omp.h>
#include <stdio.h>

using namespace std;

int performArrayTask(int size)
{
	//TODO: add code here
	long *arr = new long[size];
	long summa=0;
	long i;
	
	for ( i=0; i<size; i++) {
		arr[i]=i; 
	}
		double start_time = omp_get_wtime();
#pragma omp parallel num_threads(2)
	{
#pragma omp for
	for ( i=0; i<size; i++) {
		summa += arr[i]; 
	}
	}
	cout << summa;
	double end_time = omp_get_wtime();
	delete []arr;
	printf("zamer vremeni %lf\n", end_time - start_time);
	//system("pause");

	return 0;
}