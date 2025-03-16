#include <stdio.h>

void bubble_sort(int* a, int size);

int main(int argc, char* argv[])
{
	int a[] = { 38, 5, 34, 23, 69, 0, 1, 5, 6, 4, 14 };

	bubble_sort(a, sizeof(a)/sizeof(a[0]));

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		printf("%d ", a[i]);
	}

	return 0;
}

void bubble_sort(int* a, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1 - i; ++j)
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