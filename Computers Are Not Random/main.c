#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
	int x;
	srand(time(NULL));

	for (int i = 0; i < 30; ++i)
	{
		x = rand() % 2;
		printf("%d\n", x);
	}

}