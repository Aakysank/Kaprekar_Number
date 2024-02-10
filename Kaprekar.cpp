// Kaprekar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <math.h>

using namespace std;

bool isKaprekarNumber(long long number, int nDigits)
{
	long long beta = 0, alpha = 0;
	long long square = number * number;
	long long base_pow = long long(pow(10, nDigits));

	beta = square % base_pow;
	alpha = (square - beta) / base_pow;

	if (beta + alpha == number)
		return true;

	return false;
}

set<long long> generateKaprekarNumbers(long long minNumber, long long maxNumber, int nDigits)
{
	set<long long> kaprekarNumbers;
	for (long long num = minNumber; num <= maxNumber; num++)
	{	
		if (isKaprekarNumber(num, nDigits))
			kaprekarNumbers.insert(num);
	}

	return kaprekarNumbers;
}

int main()
{
	int nDigits = 0;
	cout << "Enter the number of digits to filter the kaprekar numbers" << "\t";
	
	cin >> nDigits;
	if (nDigits <= 0 || nDigits > 13)
	{
		std::cout << "Limit exceeded, Maximum number of digits allowed is 12" << std::endl;
		return -1;
	}

	long long minNumber = 0ll, maxNumber = 0ll;
	char* pMinNumber = NULL, * pMaxNumber = NULL, *errorData = NULL;

	set<long long> kaprekarNums;
	pMinNumber = (char*)malloc(sizeof(char) * nDigits);
	pMaxNumber = (char*)malloc(sizeof(char) * nDigits);

	if (!pMinNumber || !pMaxNumber)
		return -2;

	for (int i = 0; i < nDigits; i++)
	{
		if (i == 0)
			pMinNumber[i] = '1';
		else
			pMinNumber[i] = '0';

		pMaxNumber[i] = '9';
	}

	minNumber = strtoll(pMinNumber, &errorData, 10);
	if (errorData == pMinNumber)
	{
		cout << "Error in converting min number string to long long" << endl;
		return -3;
	}

	maxNumber = strtoll(pMaxNumber, &errorData, 10);
	if (errorData == pMaxNumber)
	{
		cout << "Error in converting max number string to long long" << endl;
		return -3;
	}

	free(pMinNumber);
	free(pMaxNumber);

	kaprekarNums = generateKaprekarNumbers(minNumber, maxNumber, nDigits);
	if (kaprekarNums.size() <= 0)
	{
		cout << "Unable to extract kaprekar numbers between the given limits" << endl;
		return -4;
	}

	cout << "The list of kaprekar numbers between " << minNumber << " and " << maxNumber << " are: " << endl;
	for (const auto& num : kaprekarNums)
	{
		cout << num << endl;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
