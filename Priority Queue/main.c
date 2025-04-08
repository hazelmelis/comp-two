/*
Name: Hazel Erkmen
Date: 4/7/2025
Time it took to complete: 2 hours
Purpose: the purpose of this assignment is to
	understand how a priority queue can be implemented using a
	heap along with the opaque object design pattern.
*/

#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main(int argc, char* argv[])
{
	PRIORITY_QUEUE hQ = priority_queue_init_default();
	if (priority_queue_is_empty(hQ))
	{
		printf("The priority queue is empty after init default.\n\n");
	}
	else
	{
		printf("The priority_queue_is_empty() function is wrong.\n");
	}

	priority_queue_insert(hQ, 0, 48);
	priority_queue_insert(hQ, 100, 47);
	priority_queue_insert(hQ, 78, 10);
	priority_queue_insert(hQ, 27, 9);
	priority_queue_insert(hQ, 120, 96);

	printf("Expected value: 96\nReal Value: %d\n\n", priority_queue_front(hQ, NULL));
	priority_queue_service(hQ);
	printf("Expected value: 47\nReal Value: %d\n\n", priority_queue_front(hQ, NULL));
	priority_queue_service(hQ);
	printf("Expected value: 10\nReal Value: %d\n\n", priority_queue_front(hQ, NULL));
	priority_queue_service(hQ);
	printf("Expected value: 9\nReal Value: %d\n\n", priority_queue_front(hQ, NULL));
	priority_queue_service(hQ);
	printf("Expected value: 48\nReal Value: %d\n\n", priority_queue_front(hQ, NULL));
	priority_queue_service(hQ);

	if (priority_queue_is_empty(hQ))
	{
		printf("The priority queue is empty after servicing every value.\n");
	}
	else
	{
		printf("The priority_queue_is_empty() function is wrong.\n");
	}

	priority_queue_destroy(&hQ);
}