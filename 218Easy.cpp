// [2015-06-08] Challenge #218 [Easy] Making numbers palindromic

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
string reversed;
string original;

bool PalindromeCheck(unsigned long long num)
{
	original = to_string(num);
	reversed = "";

	for (int i = original.length()-1; i >= 0; i--)
		reversed += original[i];

	if (original == reversed)
	{
		return true;
	}
	else
		return false;
}

int main()
{
	unsigned long long num;
	int numSteps=0;

	cout << "Enter number: \n";
	cin >> num;

	unsigned long long endNum = num;

	while (!PalindromeCheck(endNum))
	{
		endNum = endNum + stoull(reversed);
		numSteps++;
	}

	cout << num << " gets palindromic after " << numSteps << " steps: " << endNum;

	return 0;
}

