// lab1-template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>

#define DEBUG_MODE 1;

// функция, выполняющая задание обработки массива.
int performArrayTask(int size);

int getArraySize(_TCHAR* argv[])
{

	int size;

#ifdef DEBUG_MODE
	size = 1000000;
#else
	std::wstringstream sstr(argv[1]);
	sstr >> size;

#endif

	return size;
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*if (argc < 2)
	{
		printf("size undefined");
		return 1;
	}*/
	
	int size = getArraySize(argv);
	int result;

	if (size <= 0)
	{
		printf("Array size '%d' is wrong.");
		result = -1;
	}
	else
	{
		result = performArrayTask(size);
	}

#ifdef DEBUG_MODE
	printf("\nPress any key");
	getchar();
#endif

	return result;
}
