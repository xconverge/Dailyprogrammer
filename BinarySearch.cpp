// Basic Binary search
//

#include "stdafx.h"
#include <iostream>

#define arrayLength (10)
int a[arrayLength] = { 5, 7, 8, 9, 10, 11, 12, 13, 14, 15 };


using namespace std;

int BinarySearch(int *a, int high, int low, int num)
{
	int idx;

	if (high < low)
		idx = -1;
	else
	{
		int mid = (high + low) / 2;

		if (a[mid] == num)
			idx = mid;
		else
		{
			if (num < a[mid])
			{
				idx = BinarySearch(a, mid - 1, low, num);
			}
			else
			{
				idx = BinarySearch(a, high, mid + 1, num);
			}
		}
	}
	return idx;
}

int _tmain(int argc, _TCHAR* argv[])
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d: %d \n",i,a[i]);
	}

	int size = arrayLength;
	int num;

	printf("Enter number to search for: ");
	cin >> num;
	int idx = BinarySearch(a, size, 0, num);
	printf("\n%d is at index: %d", num, idx);

	return 0;
}

