#include "../inc/main.h"

//A function to find the path after finding the distance.
int backtrace(Vertex* startVertex, Vertex* endVertex, char* path[], int flag) {

	int distance = 0;
	Vertex* tmp = endVertex;
	int i = 0;
	while (strcmp(tmp->value, startVertex->value) != 0) {
		path[i++] = tmp->value;
		if (tmp->type == MOVIE) {
			distance++;
		}
		if (distance > 6 && flag == TRUE) {
			/* we don't go further anymore */
			return -1;
		}

		tmp = graph_get_vertex(graph, tmp->parent);
	}
	path[i++] = tmp->value;
	/* to indicate the end of the path while printing */
	path[i] = NULL; 
	return distance;
}
