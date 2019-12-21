#pragma once

#define MAX_QUEUE_SIZE 10000

typedef struct {
	int front;
	int rear;
	Vertex* items[MAX_QUEUE_SIZE];
}Queue;

Queue createQueue();
int enQueue(Queue* queue, Vertex* vertex);
int deQueue(Queue* queue, Vertex** vertex);
int getFront(Queue* queue, Vertex** vertex);
int isEmpty(Queue* queue);
int isFull(Queue* queue);
int printQueue(Queue* queue);