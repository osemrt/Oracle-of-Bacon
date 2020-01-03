#ifndef QUEUE_H
#define QUEUE_H

#include "graph.h"
#include "my_malloc.h"
#include "hashTable.h"
#include "common.h"

#define MAX_QUEUE_SIZE 1000000
#define TRUE 1
#define FALSE 0

typedef struct {
	int front;
	int rear;
	struct Vertex* items[MAX_QUEUE_SIZE];
}Queue;

Queue* createQueue();
int enQueue(Queue* queue, struct Vertex* vertex);
int deQueue(Queue* queue, struct Vertex** vertex);
int getFront(Queue* queue, struct Vertex** vertex);
int isEmpty(Queue* queue);
int isFull(Queue* queue);
int printQueue(Queue* queue);

#endif // !QUEUE_H


