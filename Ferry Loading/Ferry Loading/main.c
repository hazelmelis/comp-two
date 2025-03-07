#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

const int CM_PER_M = 100;

void clear_keyboard_buffer(void);
void load_queues(QUEUE hQ_left, QUEUE hQ_right);
int get_moves(QUEUE hQ_left, QUEUE hQ_right, int ferry_length);

int main(int argc, char* argv[])
{
	int noc; 
	int total_tests; 
	int ferry_length;
	int i;

	noc = scanf("%d", &total_tests);

	for (i = 0; i < total_tests; i++)
	{
		QUEUE hQ_left = queue_init_default();
		if (hQ_left == NULL)
		{
			printf("Failed to allocate space for queue.\n");
			exit(1);
		}

		QUEUE hQ_right = queue_init_default();
		if (hQ_right == NULL)
		{
			printf("Failed to allocate space for queue.\n");
			exit(1);
		}

		noc = scanf("%d", &ferry_length);
		load_queues(hQ_left, hQ_right);
		printf("%d\n", get_moves(hQ_left, hQ_right, ferry_length));

		queue_destroy(&hQ_left);
		queue_destroy(&hQ_right);
	}

	return 0;
}

void clear_keyboard_buffer(void)
{
	char c;
	int noc = scanf("%c", &c);

	while (c != '\n' && noc == 1)
	{
		noc = scanf("%c", &c);
	}
}

void load_queues(QUEUE hQ_left, QUEUE hQ_right)
{
	int noc;
	int total_cars;
	char side;
	int i;
	int car_length;

	noc = scanf("%d", &total_cars);
	for (i = 0; i < total_cars; i++)
	{
		noc = scanf("%d", &car_length);
		noc = scanf(" %c", &side);
		clear_keyboard_buffer();

		if (side == 'l')
		{
			queue_insert(hQ_left, car_length);
		}
		else if (side == 'r')
		{
			queue_insert(hQ_right, car_length);
		}
	}
}

int get_moves(QUEUE hQ_left, QUEUE hQ_right, int ferry_length)
{
	int total_moves = 0;
	int ferry_remaining;
	typedef enum side { LEFT, RIGHT }Side;
	Side current_side = LEFT;
	ferry_length *= CM_PER_M;

	while (queue_empty(hQ_left) == FALSE || queue_empty(hQ_right) == FALSE)
	{
		ferry_remaining = ferry_length;

		if (current_side == LEFT)
		{
			while (queue_empty(hQ_left) == FALSE && queue_front(hQ_left, NULL) <= ferry_remaining)
			{
				ferry_remaining -= queue_front(hQ_left, NULL);
				queue_service(hQ_left);
			}

			total_moves++;
			current_side = RIGHT;
		}
		else if (current_side == RIGHT)
		{
			while (queue_empty(hQ_right) == FALSE && queue_front(hQ_right, NULL) <= ferry_remaining)
			{
				ferry_remaining -= queue_front(hQ_right, NULL);
				queue_service(hQ_right);
			}

			total_moves++;
			current_side = LEFT;
		}
	}

	return total_moves;
}