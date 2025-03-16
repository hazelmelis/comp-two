#include <stdio.h>

void bubble_sort(int* a, int size);

int main(int argc, char* argv[])
{
	int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	bubble_sort(a, 10);

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		printf("%d ", a[i]);
	}

	return 0;
}

void bubble_sort(int* a, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}