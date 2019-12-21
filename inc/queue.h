#pragma once

#define MAX_QUEUE_SIZE 10000

typedef struct {
	int front;
	int rear;
	int items[MAX_QUEUE_SIZE];
}Queue;

Queue createQueue();