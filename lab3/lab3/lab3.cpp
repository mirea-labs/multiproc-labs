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

// ��������������� ���������� �������
void GenerateNumbers(LPVOID);
void ProcessNumbers(LPVOID context);

// ����� �����
int _tmain(int argc, _TCHAR* argv[])
{	
	int sum;

	// ����� ���������� ��������� ����� (��� �������������).
	//srand(200);

	GenerateNumbers(NULL);
	ProcessNumbers(&sum);

	return 0;
}

void GenerateNumbers(LPVOID)
{
	for (size_t i = 0; i < NUMBER_COUNT; i++)
	{
		// ������� � ������� ��������� ����� 0-99
		numbers.push(rand()%100);
		cout << "Generated number " << numbers.back() << endl;
		// ��� ��� ������� (�������� ������ ������)
		Sleep(2000);
	}
}

void ProcessNumbers(LPVOID context)
{
	while (numbers.size() != 0)
	{
		// �������� ��������� ������� �� �������
		int current = numbers.front();
		cout << "Processing element " << current << endl;
		// ������ ��� �� �������
		numbers.pop();
		// ������ ���������� ��������� � ������� ����
		int* sumAddress = static_cast<int*>(context);
		// �������� � ����������, ������������� �����
		*sumAddress+=current;
		// ��� ��� ������� (�������� ������ ������)
		Sleep(2000);
	}
}