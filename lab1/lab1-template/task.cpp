
#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
#include <string>
#include "conio.h"
#include <stdio.h>
#include "omp.h"


using namespace std;

int performArrayTask(int size)
{
	//TODO: add code here
	long *arr = new long[size];
	long i;
	long sum = 0; // сумма элементов массива
	double start_time, end_time;

	for (i=0;i<size;i++){
		arr[i] = i;
	};

	start_time = omp_get_wtime();
#pragma omp parallel// num_threads(2)
	{
		long local_sum = 0;
#pragma omp for
	for (i=0; i<size; i++){  
		sum += arr[i];
	};

	sum+=local_sum;

	end_time = omp_get_wtime(); 

	}

	cout <<"Summa: " <<sum << endl;
    printf("Zamer vremeni %lf\n", end_time-start_time); 

	delete []arr;
	return 0;
}