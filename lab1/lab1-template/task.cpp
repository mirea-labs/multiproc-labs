
#include "stdafx.h"
#include <iostream>
#include "omp.h"

using namespace std;

int performArrayTask(int size)
{
	//TODO: add code here

	long *arr = new long[size];
	long *i = new long[size];
	double start_time, end_time;
	
	int n=0;
	int sum = 0;
    for ( long i = 0; i < size; i++ )
         arr[i] = i;  
	
	start_time = omp_get_wtime();
#pragma omp parallel num_threads(2)
	{
		long local_sum = 0;
#pragma omp for
		for ( long i = 0; i < size; i++ ) 
        {
			local_sum += arr[i]; 
			//printf("branch %d completed iteration %d\n", omp_get_thread_num(), n);
			
		}
		sum+=local_sum;
	}
	end_time = omp_get_wtime();
    cout << "sum = " << sum << endl;
	printf(" Time counting= %lf\n", end_time-start_time);
    system("pause");
	return 0;

}