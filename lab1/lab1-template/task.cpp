
#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "omp.h"
#include "locale"
#include "time.h"

using namespace std;

int performArrayTask(long size)
{
	setlocale(LC_ALL, "Rus");
	long *arr = new long[size];
	long S;
	S = 0;
	for (long i=0; i<size; i++)
		{
			arr[i] = i;
		}
	double start_time = omp_get_wtime();
	#pragma omp parallel num_threads (4)
	{
		long local_sum = 0;
		#pragma omp for
		for (long i=0; i<size; i++)
		{
			local_sum += arr[i];
		}
		S += local_sum;
	}
	delete []arr;
	double end_time = omp_get_wtime();
	cout<<"Сумма всех элементов: "<<(unsigned long)S<<"\n";
	printf ("Замер времени %lf\n", end_time-start_time);

	return 0;
}
