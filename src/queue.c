#include "../inc/main.h"

Queue createQueue() {
	Queue queue;
	queue.front = -1;
	queue.rear = -1;
	return queue;
}

int enQueue(Queue* queue, int x) {

	if (isFull(queue)) {
		return FALSE;
	}
	else if (isEmpty(queue)) {
		queue->front = queue->rear = 0;
	}
	else {
		queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
	}
	queue->items[queue->rear] = x;
	return TRUE;
}

int deQueue(Queue* queue, int* x) {
	if (queue->front == queue->rear) {
		*x = queue->items[queue->front];
		queue->front = queue->rear = -1;
		return TRUE;
	}
	else if (!isEmpty(queue)) {
		*x = queue->items[queue->front];
		queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
		return TRUE;
	}
	return FALSE;
}

int getFront(Queue* queue, int* x) {
	if (!isEmpty(queue)) {
		*x = queue->items[queue->front];
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
			printf("%d ", queue->items[i % MAX_QUEUE_SIZE]);
		}
		printf("%d ", queue->items[queue->rear]);
		printf("] <- rear\n");
	}
	else {
		printf("\nEmpty Queue!\n");
		return FALSE;
	}
}