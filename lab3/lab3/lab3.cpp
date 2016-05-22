// lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <iostream>
#include <random>
#include <Windows.h>

using namespace std;

queue<int> numbers;
const int NUMBER_COUNT = 100;
volatile bool GeneratorCompleted = FALSE;

// предварительное объявление функций
void GenerateNumbers();
void ProcessNumbers(int*);

// Точка входа
int _tmain(int argc, _TCHAR* argv[])
{	
	int sum;

	// сброс генератора случайных чисел (при необходимости).
	//srand(200);

	GenerateNumbers();
	ProcessNumbers(&sum);

	return 0;
}

void GenerateNumbers()
{
	for (size_t i = 0; i < NUMBER_COUNT; i++)
	{
		// помещаю в очередь случайное число 0-99
		numbers.push(rand()%100);
		cout << "Generated number " << numbers.back() << endl;
		// жду две секунды (имитация долгой работы)
		Sleep(2000);
	}
	GeneratorCompleted = TRUE;
}

void ProcessNumbers(int* sumAddress)
{
	while (!GeneratorCompleted)
	{
		while (numbers.size() != 0)
		{
			// прочитал очередной элемент из очереди
			int current = numbers.front();
			cout << "Processing element " << current << endl;
			// удалил его из очереди
			numbers.pop();
			// прибавил к переменной, накапливающей сумму
			*sumAddress += current;
			// жду две секунды (имитация долгой работы)
			Sleep(1000);
		}
	}
}