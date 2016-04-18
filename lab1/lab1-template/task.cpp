
#include "stdafx.h"
#include <stdio.h>
#include "iostream"
#include <omp.h>

using namespace std;
int performArrayTask(int size)
{    
	setlocale(LC_ALL);
	long s;
	s = 0;
	long *arr = new long[size];

	for(long i=0; i<size; i++)
    #pragma omp for
	{
		arr[i] = i;
		s=s+arr[i];
	}
	delete []arr;
	double end_time=omp_get_wtime;
	return 0;
}