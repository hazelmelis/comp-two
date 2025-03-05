#ifndef QUEUE_H
#define QUEUE_H
#include "status.h"

typedef void* QUEUE;

QUEUE queue_init_default(void);

void print(QUEUE hQ);

Boolean queue_empty(QUEUE hQ);

Status queue_insert(QUEUE hQ, int data);

int queue_front(QUEUE hQ, Status* pStatus);

Status queue_service(QUEUE hQ);

void queue_destroy(QUEUE* phQ);

#endif