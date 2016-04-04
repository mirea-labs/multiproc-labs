
#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int performArrayTask(int size)
{
	//TODO: add code here
	size= 10000;
	long *arr = new long[size];
	long sum=0;
	
	for (long i=0;i<size;i++)
	{
		arr[i]=i;
	}
	double start_time = omp_get_wtime();
#pragma omp parallel num_threads(4)
	{
#pragma omp for 
		for (long i = 0; i < size; i++)
		{
			sum += arr[i];
		}
	}
	cout<<sum<<endl;
	double end_time=omp_get_wtime();
	printf("zamer vremeni %lf\n", end_time-start_time);

	return 0;
}