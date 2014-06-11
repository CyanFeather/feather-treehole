/*
Test set:
https://www.paypalobjects.com/en_US/vhelp/paypalmanager_help/credit_card_numbers.htm
*/

#include <stdio.h>
#include "cs50.h"

int main(void)
{
	long long int numCredit, numCalc;
	int sum = 0;
	int temp;
	do
	{
		printf("Credit card number: ");
		numCredit = GetLongLong();
	}
	while (numCredit < 0);

	// Test credit card number
	numCalc = numCredit;
	while (numCalc != 0)
	{
		sum += (numCalc % 10);
		numCalc /= 10;

		temp = (numCalc % 10) * 2;
		numCalc /= 10;
		while (temp != 0)
		{
			sum += (temp % 10);
			temp /= 10;
		}
	}

	printf("Sum is %d\n", sum);

	if (sum % 10 == 0)
	{
		while (numCredit > 99)
			numCredit /= 10;

		switch (numCredit)
		{
			case 34:
			case 37:
				{
					printf("AMEX\n");
					break;
				}
			case 51:
			case 52:
			case 53:
			case 54:
			case 55:
				{
					printf("MASTERCARD\n");
					break;
				}
			case 40:
			case 41:
			case 42:
			case 43:
			case 44:
			case 45:
			case 46:
			case 47:
			case 48:
			case 49:
				{
					printf("VISA\n");
					break;
				}
			default:
				{
					printf("VALID\n");
					break;
				}
		}
	}
	else
		printf("INVALID\n");
	return 0;
}
