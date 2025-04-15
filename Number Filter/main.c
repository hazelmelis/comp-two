#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

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
	printf("%d\n", max_input);

	
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