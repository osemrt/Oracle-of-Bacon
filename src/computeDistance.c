#include "../inc/main.h"

//A function to compute the distance between two actors.
//int flag is used to check condition for kevin-backon number
//if the user selects the second option then we will not go more than six distances
int computeDistance(char* actor1, char* actor2, char* path[], int flag) {
	Vertex* current = NULL;
	Vertex* vertex = NULL;
	linkedlist_node* neighbor;
	Queue* queue = createQueue();
	Vertex* start_vertex = graph_get_vertex(graph, actor2);
	enQueue(queue, start_vertex);

	while (isEmpty(queue) != TRUE) {
		
		deQueue(queue, &current);
		if (strcmp(current->value, actor1) == 0) {
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