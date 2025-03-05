#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char* argv[])
{
	QUEUE hQ = queue_init_default();
	if (hQ == NULL)
	{
		printf("Failed to allocate space for queue.\n"); exit(1);
	}

	queue_insert(hQ, 200);
	printf("%d\n", queue_front(hQ, NULL));
	queue_insert(hQ, 5);
	print(hQ);

	queue_insert(hQ, 8);
	print(hQ);

	queue_service(hQ);
	queue_service(hQ);
	print(hQ);


	queue_destroy(&hQ);
	return 0;
}