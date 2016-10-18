// Challenge 287 [Easy].cpp : Defines the entry point for the console application.
/* [2016-10-10] Challenge #287 [Easy] Kaprekar's Routine
https://www.reddit.com/r/dailyprogrammer/comments/56tbds/20161010_challenge_287_easy_kaprekars_routine/
https://en.wikipedia.org/wiki/6174_(number)

Kaprekar's Routine is my first C++ project, although it seems to be, so far no different than C.
I used three functions, two to sort the four digit number in a certain order and one to check whether
the give number is actually a four digit number and make arrangements, such that it is.
One of the omitted rules is that I don't check whether the number is made out of at least two different digits.
This was quite fun, 10/10 will do something like this again.*/

#include "stdafx.h"
#include <iostream>

/*Sorts an integer, smaller than 10 000, from the highest to lowest*/
int sort10(int integer)
{
	int list[4];
	int sortedList[4];
	int position = 0;

	/*an array is made to sort individual numbers*/
	list[0] = integer / 1000;
	list[1] = (integer / 100) % 10;
	list[2] = (integer % 100) / 10;
	list[3] = integer % 10;

	for (int n = 0; n < 4; n++)
	{
		/*Check a number against other numbers, the amount of smaller minus one is the position*/
		for (int i = 0; i < 4; i++)
		{
			if (list[n] < list[i])
			{
				position += 1;
			}
			if (list[n] == list[i] && i != n)
			{
				if (n > i)
				{
					position += 1;
				}
			}

		}
		sortedList[position] = list[n];
		position = 0;
	}


	/* Returns an integer */
	return sortedList[0] * 1000 + sortedList[1] * 100 + sortedList[2] * 10 + sortedList[3];
}

/*Sort an integer, smaller than 10 000, from lowest to highest*/
int sort01(int integer)
{

	int list[4];
	int sortedList[4];
	int position = 3;

	list[0] = integer / 1000;
	list[1] = (integer / 100) % 10;
	list[2] = (integer % 100) / 10;
	list[3] = integer % 10;

	for (int n = 0; n < 4; n++)
	{
		/*Check a number against other numbers, 4 minus the amount of < is the position*/
		for (int i = 0; i < 4; i++)
		{
			if (list[n] < list[i])
			{
				position -= 1;
			}

			if (list[n] == list[i] && i != n)
			{
				if (n > i)
				{
					position -= 1;
				}
			}
		}
		sortedList[position] = list[n];
		position = 3;
	}
	
	return sortedList[0] * 1000 + sortedList[1] * 100 + sortedList[2] * 10 + sortedList[3];
}

/* Check whether a number is a four digit one, if not, adds multiplies it by a factor of ten*/
/* I can afford to do this because I don't care about the given number itself but rather the sorted one*/
int zeroes(int integer)
{
	if (integer < 10)
		return integer * 1000;

	if (integer < 100)
		return integer * 100;

	if (integer < 1000)
		return integer * 10;
	else
		return integer;
}

int main()
{
	int number;
	int numberOne;
	int numberTwo;

	int noIterations = 0;

	std::cout << "Give me a four digit number\n";
	std::cin >> number;

	number = zeroes(number);
	

	while (number != 6174)
	{
		numberOne = sort10(number);

		numberTwo = sort01(number);

		/* Kaprekar's routine */
		number = numberOne - numberTwo;
		
		noIterations += 1;

	}

	std::cout << "The final number is, as expected, " << number << "\n";
	std::cout << "The number of iterations is " << noIterations << "\n";

    return 0;
}

