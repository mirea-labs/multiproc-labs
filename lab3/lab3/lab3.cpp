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

// предварительное объявление функций
void GenerateNumbers(LPVOID);
void ProcessNumbers(LPVOID context);

// Точка входа
int _tmain(int argc, _TCHAR* argv[])
{	
	int sum;

	// сброс генератора случайных чисел (при необходимости).
	//srand(200);

	GenerateNumbers(NULL);
	ProcessNumbers(&sum);

	return 0;
}

void GenerateNumbers(LPVOID)
{
	for (size_t i = 0; i < NUMBER_COUNT; i++)
	{
		// помещаю в очередь случайное число 0-99
		numbers.push(rand()%100);
		cout << "Generated number " << numbers.back() << endl;
		// жду две секунды (имитация долгой работы)
		Sleep(2000);
	}
}

void ProcessNumbers(LPVOID context)
{
	while (numbers.size() != 0)
	{
		// прочитал очередной элемент из очереди
		int current = numbers.front();
		cout << "Processing element " << current << endl;
		// удалил его из очереди
		numbers.pop();
		// привел переменную контекста к нужному типу
		int* sumAddress = static_cast<int*>(context);
		// прибавил к переменной, накапливающей сумму
		*sumAddress+=current;
		// жду две секунды (имитация долгой работы)
		Sleep(2000);
	}
}