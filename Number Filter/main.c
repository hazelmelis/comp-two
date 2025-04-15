/**********************************************************************
Program: Number Filter
Author: Hazel Erkmen
Date: 4/14/25
Time spent: 3 hours
Purpose: The purpose of this program is to think about all the data 
structures learned in this course and choose the right one such that
a seemingly difficult problem can be solved with ease. In this case,
using the bit flags allows us to easily hold a boolean value for all 
2,000,000,000 possible input numbers. In an array of integers, each
successive bit is a number from 0 - 2,000,000,000, 1 meaning it has
already been entered before, and 0 meaning it is a new entry. 
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 2000000000
const int BITS_PER_INT = sizeof(int) * 8;

int main(int argc, char* argv[])
{
	unsigned int* bit_flags = malloc((MAX_VALUE / BITS_PER_INT + 1) * sizeof(unsigned int));
	if (bit_flags == NULL)
	{
		printf("Failed to allocate space for bit flags.\n");
		exit(1);
	}

	int input;
	int array_index;
	int bit_index;
	scanf("%d", &input);
	int max_input = input;
	while (input != -1)
	{
		if (input > max_input)
		{
			max_input = input;
		}

		array_index = input / BITS_PER_INT;
		bit_index = input % BITS_PER_INT;
		
		if (!(bit_flags[array_index] >> bit_index & 1))
		{
			bit_flags[array_index] = bit_flags[array_index] | 1 << bit_index;
		}

		scanf("%d", &input);
	}
	
	for (int i = 0; i < max_input / BITS_PER_INT + 1; ++i)
	{
		for (int j = 0; j < 32; ++j)
		{
			if (bit_flags[i] >> j & 1)
			{
				printf("%d\n", j + i * BITS_PER_INT);
			}
		}
	}

	free(bit_flags);
}