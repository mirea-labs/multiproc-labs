
#include "stdafx.h"
#include "iostream"
#include <stdio.h>


using namespace std;

int performArrayTask(int size)
{
	//TODO: add code here
	setlocale(LC_ALL, "Russian");

	long *arr = new long[size];
	long sum=0;
	double start_time, end_time;
	int i;
	
	for (long i=0; i< size; i++)
	{
		arr[i]=i;
	}
	start_time = omp_get_wtime();
#pragma omp parallel num_threads(8)
	{
#pragma omp for 
		for (long i=0; i< size; i++)
		{
			sum +=arr[i];
		}
	}
	end_time = omp_get_wtime(); 
	cout << sum << endl;
	printf("замер времени %lf\n", end_time-start_time); 
	system("pause");

	return 0;
}