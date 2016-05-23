// lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <iostream>
#include <random>
#include <Windows.h>

using namespace std;

CRITICAL_SECTION CS;
queue<int> numbers;
const int NUMBER_COUNT = 100;
volatile bool GeneratorCompleted = FALSE;

// ïðåäâàðèòåëüíîå îáúÿâëåíèå ôóíêöèé
void GenerateNumbers();
void ProcessNumbers(int*);

DWORD WINAPI ThreadProc1(LPVOID lpParameter)
{
	GenerateNumbers();
	return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{   int sum;
	ProcessNumbers(&sum);
	return 0;
}

// Òî÷êà âõîäà
int _tmain(int argc, _TCHAR* argv[])
{	
	//int sum;

	// ñáðîñ ãåíåðàòîðà ñëó÷àéíûõ ÷èñåë (ïðè íåîáõîäèìîñòè).
	//srand(200);

	// GenerateNumbers();
	// ProcessNumbers(&sum);
	InitializeCriticalSection(&CS);
	HANDLE hThreads[3];

	hThreads[0] = CreateThread(NULL, NULL, ThreadProc1, NULL, 0, 0);
	hThreads[1] = CreateThread(NULL, NULL, ThreadProc2, NULL, 0, 0);
	hThreads[2] = CreateThread(NULL, NULL, ThreadProc2, NULL, 0, 0);

	WaitForMultipleObjects(3,hThreads,TRUE,INFINITE);

	system("pause");
	return 0;
}


void GenerateNumbers()
{
	for (size_t i = 0; i < NUMBER_COUNT; i++)
	{   
		EnterCriticalSection(&CS);
		// ïîìåùàþ â î÷åðåäü ñëó÷àéíîå ÷èñëî 0-99
		numbers.push(rand()%100);
		cout << "Generated number " << numbers.back() << endl;
		// æäó äâå ñåêóíäû (èìèòàöèÿ äîëãîé ðàáîòû)
		
		
		LeaveCriticalSection( &CS);
		Sleep(500);
	}
	GeneratorCompleted = TRUE;
}

void ProcessNumbers(int* sumAddress)
{
	while (!GeneratorCompleted)
	{
		EnterCriticalSection( &CS);

		if (numbers.size() != 0)
		{
			
			// ïðî÷èòàë î÷åðåäíîé ýëåìåíò èç î÷åðåäè
			int current = numbers.front();
			cout << "Processing element " << current << endl;
			// ïðèáàâèë ê ïåðåìåííîé, íàêàïëèâàþùåé ñóììó
			*sumAddress += current;
			// óäàëèë åãî èç î÷åðåäè
			numbers.pop();
			
			// æäó äâå ñåêóíäû (èìèòàöèÿ äîëãîé ðàáîòû)
			
			
		}
		LeaveCriticalSection( &CS);
		Sleep(500);
	}
}
// Ïîäñêàçêà î òîì, êàê âûãëÿäèò ôóíêöèÿ - òåëî ïîòîêà
/*DWORD WINAPI ThreadBody(LPVOID context)
{
	return 0;
}*/