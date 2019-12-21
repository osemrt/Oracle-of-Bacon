#include "../inc/main.h"

int computeDistance(char* actor1, char* actor2, char path[], int flag) {


	Vertex* current = NULL;
	Vertex* vertex = NULL;
	linkedlist_node* neighbor;
	int distance = 0;
	Queue* queue = createQueue();
	Vertex* start_vertex = graph_get_vertex(graph, actor1);
	enQueue(queue, start_vertex);

	while (isEmpty(queue) != TRUE) {
		
		deQueue(queue, &current);
		if (strcmp(current->value, actor2) == 0) {
			return backtrace(start_vertex, current, path, flag);
		}

		neighbor = current->edges->head;
		while (neighbor != NULL) {
			vertex = graph_get_vertex(graph, neighbor->val);
			if (vertex->visited == FALSE) {
				vertex->visited = TRUE;
				vertex->parent = current->value;
				enQueue(queue, vertex);
			}
			neighbor = neighbor->next;
		}


	}

	

}