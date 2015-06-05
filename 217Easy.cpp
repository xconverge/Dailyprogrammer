//Challenge #217 [Easy] Lumberjack Pile Problem

#include "stdafx.h"
#include <iostream>;
#include <string>;
#include <vector>

using namespace std;

int size, logs;
vector <vector <int>> logCnt;

void InitValues(int testcase)
{
	switch (testcase)
	{
	case 1:
		size = 3;
		logs = 7;
		logCnt = { { 1, 1, 1 }, { 2, 1, 3 }, { 1, 4, 1 } };
		break;
	case 2:
		size = 4;
		logs = 200;
		logCnt = { { 15, 12, 13, 11, }, { 19, 14, 8, 18 }, { 13, 14, 17, 15 }, { 7, 14, 20, 7 } };
		break;
	case 3:
		size = 15;
		logs = 2048;
		logCnt = { { 5, 15, 20, 19, 13, 16, 5, 2, 20, 5, 9, 15, 7, 11, 13 },
		{ 17, 13, 7, 17, 2, 17, 17, 15, 4, 17, 4, 14, 8, 2, 1 },
		{ 13, 8, 5, 2, 9, 8, 4, 2, 2, 18, 8, 12, 9, 10, 14 },
		{ 18, 8, 13, 13, 4, 4, 12, 19, 3, 4, 14, 17, 15, 20, 8 },
		{ 19, 9, 15, 13, 9, 9, 1, 13, 14, 9, 10, 20, 17, 20, 3 },
		{ 12, 7, 19, 14, 16, 2, 9, 5, 13, 4, 1, 17, 9, 14, 19 },
		{ 6, 3, 1, 7, 14, 3, 8, 6, 4, 18, 13, 16, 1, 10, 3 },
		{ 16, 3, 4, 6, 7, 17, 7, 1, 10, 10, 15, 8, 9, 14, 6 },
		{ 16, 2, 10, 18, 19, 11, 16, 6, 17, 7, 9, 13, 10, 5, 11 },
		{ 12, 19, 12, 6, 6, 9, 13, 6, 13, 12, 10, 1, 13, 15, 14 },
		{ 19, 18, 17, 1, 10, 3, 1, 6, 14, 9, 10, 17, 18, 18, 7 },
		{ 7, 2, 10, 12, 10, 20, 14, 13, 19, 11, 7, 18, 10, 11, 12 },
		{ 5, 16, 6, 8, 20, 17, 19, 17, 14, 10, 10, 1, 14, 8, 12 },
		{ 19, 10, 15, 5, 11, 6, 20, 1, 5, 2, 5, 10, 5, 14, 14 },
		{ 12, 7, 15, 4, 18, 11, 4, 10, 20, 1, 16, 18, 7, 13, 15 } };
		break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

	for (int p = 1; p < 4; p++)
	{
		InitValues(p);

		int logNum = logs;
		int min = 0;
		int minRow = 0;
		int minCol = 0;

		while (logNum > 0)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (logCnt[i][j] < logCnt[minRow][minCol])
					{
						min = logCnt[i][j];
						minRow = i;
						minCol = j;
					}
				}
			}

			logCnt[minRow][minCol]++;
			logNum--;
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << logCnt[i][j] << " ";
			}
			cout << endl;
		}

	}
	return 0;
}