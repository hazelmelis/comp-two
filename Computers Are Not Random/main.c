#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
	int x;
	srand(time(NULL));

	for (int i = 0; i < 30; ++i)
	{
		x = rand() % 6 + 1;
		printf("%d\n", x);
	}
}