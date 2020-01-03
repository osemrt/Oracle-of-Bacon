#include "queue.h"

Queue* createQueue();
int enQueue(Queue* queue, Vertex* vertex);
int deQueue(Queue* queue, Vertex** vertex);
int getFront(Queue* queue, Vertex** vertex);
int isEmpty(Queue* queue);
int isFull(Queue* queue);
int printQueue(Queue* queue);

Queue* createQueue() {
	Queue* queue = (Queue*)my_malloc(QUEUE, 1);
	queue->front = -1;
	queue->rear = -1;
	return queue;
}

int enQueue(Queue* queue, Vertex* vertex) {

	if (isFull(queue)) {
		return FALSE;
	}
	else if (isEmpty(queue)) {
		queue->front = queue->rear = 0;
	}
	else {
		queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
	}
	queue->items[queue->rear] = vertex;
	return TRUE;
}

int deQueue(Queue* queue, Vertex** vertex) {
	if (queue->front == queue->rear) {
		*vertex = queue->items[queue->front];
		queue->front = queue->rear = -1;
		return TRUE;
	}
	else if (!isEmpty(queue)) {
		*vertex = queue->items[queue->front];
		queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
		return TRUE;
	}
	return FALSE;
}

int getFront(Queue* queue, Vertex** vertex) {
	if (!isEmpty(queue)) {
		*vertex = queue->items[queue->front];
		return TRUE;
	}
	return FALSE;
}

int isEmpty(Queue* queue) {
	return queue->front == -1 && queue->rear == -1 ? TRUE : FALSE;
}

int isFull(Queue* queue) {
	return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front ? TRUE : FALSE;
}

int printQueue(Queue* queue) {
	printf("\nPrinting the queue...");
	if (!isEmpty(queue)) {
		printf("\nfront-> [ ");
		for (int i = queue->front; i != queue->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
			printf("%s ", queue->items[i % MAX_QUEUE_SIZE]->value);
		}
		printf("%s ", queue->items[queue->rear]->value);
		printf("] <- rear\n");
	}
	else {
		printf("\nEmpty Queue!\n");
		return FALSE;
	}

	return TRUE;
}