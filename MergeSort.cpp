// Test for number of inversions in an input file (value at index = i is greater than value at index > i)

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

double numInversions = 0;
#define SIZE (100000)

void Merge(int a[], const int low, const int high, int mid)
{		
	int * tmp = new int[high + 1 - low];
	int idx = 0;

	int i = low;
	int j = mid + 1;

	while ((i <= mid) && (j <= high))
	{
		if (a[i] <= a[j])
		{
			tmp[idx] = a[i];
			i++;
		}
		else
		{
			tmp[idx] = a[j];
			numInversions +=  mid + 1 - i;
			j++;
		}
		idx++;
	}
	
	while (i <= mid)
	{
		tmp[idx] = a[i];
		i++;
		idx++;
	}

	while (j <= high)
	{
		tmp[idx] = a[j];
		j++;
		idx++;
	}
	
	for (int p = 0; p <= high-low; p++)
	{
		a[p + low] = tmp[p];
	}

	delete[] tmp;
}

void merge_sort(int a[], int low, int high)
{
	int mid;
	int inv1 = 0, inv2 = 0, inv3 = 0;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		Merge(a, low, high, mid);
	}
}

void BruteForce(int a[])
{
	//Brute force inversion counter for verification
	double bruteCnt = 0;
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (a[i] > a[j])
				bruteCnt++;
		}
	}
	printf("Brute Inversions: %.0f\n", bruteCnt);
}


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream file("C:/Users/sean/Downloads/IntegerArray.txt", ios::in);

	int a[SIZE];

	int num;
	for (int i = 0; i < SIZE; i++)
	{
		file >> num;
		a[i] = num;
	}
	file.close();
	BruteForce(a);

	merge_sort(a, 0, SIZE-1);

	printf("Merge Inversions: %.0f\n", numInversions);

	getchar();

	return 0;
}