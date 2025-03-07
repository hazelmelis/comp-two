#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node Node;
struct node
{
	int value;
	Node* next;
};

struct queue
{
	Node* head;
	Node* tail;
};
typedef struct queue Queue;

QUEUE queue_init_default(void)
{
	Queue* pQ = (Queue*)malloc(sizeof(Queue));
	if (pQ == NULL)
	{
		return NULL;
	}

	pQ->head = NULL;
	pQ->tail = NULL;
	
	return (QUEUE)pQ;
}

Boolean queue_empty(QUEUE hQ)
{
	Queue* pQ = (Queue*)hQ;
	return (pQ->head == NULL)?TRUE:FALSE;
}

Status queue_insert(QUEUE hQ, int data)
{
	Queue* pQ = (Queue*)hQ;
	
	Node* new_tail = (Node*)malloc(sizeof(Node));
	if (new_tail == NULL) return FAILURE;

	new_tail->value = data;
	new_tail->next = NULL;

	if (pQ->head == NULL)
	{
		pQ->head = new_tail;
		pQ->tail = new_tail;
	}
	else
	{
		pQ->tail->next = new_tail;
		pQ->tail = pQ->tail->next;
	}

	return SUCCESS;
}

void print(QUEUE hQ)
{
	Queue* pQ = (Queue*)hQ;
	
	Node* temp = pQ->head;
	while (temp != NULL)
	{
		printf("%d->", temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
}

int queue_front(QUEUE hQ, Status* pStatus)
{
	if (queue_empty(hQ) == TRUE)
	{
		if (pStatus != NULL) *pStatus = FAILURE;
		return -101;
	}

	if (pStatus != NULL) *pStatus = SUCCESS;

	Queue* pQ = (Queue*)hQ;
	return pQ->head->value;
}

Status queue_service(QUEUE hQ)
{
	if (queue_empty(hQ) == TRUE) return FAILURE;

	Queue* pQ = (Queue*)hQ;

	Node* temp = pQ->head;
	pQ->head = pQ->head->next;
	free(temp);
}

void queue_destroy(QUEUE* phQ)
{
	Queue* pQ = (Queue*)*phQ;

	Node* temp = pQ->head;
	while (pQ->head != NULL)
	{
		pQ->head = pQ->head->next;
		free(temp);
		temp = pQ->head;
	}

	free(pQ);
	*phQ = NULL;
}