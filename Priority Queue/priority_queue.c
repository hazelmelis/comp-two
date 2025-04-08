#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

typedef struct key_value
{
	int key;
	int value;
} KeyValue;

typedef struct priority_queue
{
	int size;
	int capacity;
	KeyValue* heap;
} Priority_queue;

void fix_up(KeyValue heap[], int index);
void fix_down(KeyValue heap[], int size, int index);

PRIORITY_QUEUE priority_queue_init_default(void)
{
	Priority_queue* pQ = (Priority_queue*)malloc(sizeof(Priority_queue));
	if (pQ != NULL)
	{
		pQ->size = 0;
		pQ->capacity = 1;
		pQ->heap = (KeyValue*)malloc(sizeof(KeyValue) * pQ->capacity);
		if (pQ->heap == NULL)
		{
			free(pQ);
			return NULL;
		}
	}
	return pQ;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
	Priority_queue* pQ = (Priority_queue*)hQueue;

	KeyValue new_item;
	new_item.key = priority_level;
	new_item.value = data_item;

	if (pQ->size >= pQ->capacity)
	{
		KeyValue* temp = realloc(pQ->heap, sizeof(KeyValue) * pQ->capacity * 2);
		if (temp == NULL)
		{
			return FAILURE;
		}
		pQ->heap = temp;
		pQ->capacity *= 2;
	}
	pQ->heap[pQ->size] = new_item;
	pQ->size++;
	fix_up(pQ->heap, pQ->size - 1);

	return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
	Priority_queue* pQ = (Priority_queue*)hQueue;
	if (pQ->size > 0)
	{
		pQ->heap[0] = pQ->heap[pQ->size - 1];
		pQ->size--;
		fix_down(pQ->heap, pQ->size, 0);
		return SUCCESS;
	}
	return FAILURE;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
	Priority_queue* pQ = (Priority_queue*)hQueue;
	if (pQ->size > 0)
	{
		if (pStatus != NULL)
		{
			*pStatus = SUCCESS;
		}
		return pQ->heap[0].value;
	}
	else
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return -1337;
	}
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
	Priority_queue* pQ = (Priority_queue*)hQueue;
	return (pQ->size <= 0) ? TRUE : FALSE;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
	Priority_queue* pQ = (Priority_queue*)*phQueue;
	free(pQ->heap);
	free(pQ);
	*phQueue = NULL;
}

void fix_up(KeyValue heap[], int index)
{
	int parent_index = (index - 1) / 2;
	if (index > 0)
	{
		if (heap[index].key > heap[parent_index].key && index != 0)
		{
			KeyValue temp = heap[index];
			heap[index] = heap[parent_index];
			heap[parent_index] = temp;
			fix_up(heap, parent_index);
		}
	}
}

void fix_down(KeyValue heap[], int size, int index)
{
	int left_child_index = 2 * index + 1;
	int right_child_index = left_child_index + 1;
	int greater_child_index;

	if (left_child_index < size)
	{
		if (right_child_index >= size)
		{
			greater_child_index = left_child_index;
		}
		else
		{
			greater_child_index = (heap[left_child_index].key > heap[right_child_index].key) ? left_child_index : right_child_index;
		}
		if (heap[index].key < heap[left_child_index].key || heap[index].key < heap[right_child_index].key)
		{
			KeyValue temp = heap[index];
			heap[index] = heap[greater_child_index];
			heap[greater_child_index] = temp;
			fix_down(heap, size, greater_child_index);
		}
	}
}