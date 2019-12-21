#include "../inc/main.h"

int backtrace(Vertex* startVertex, Vertex* endVertex, int flag) {

	int i = 0;
	int distance = 0;
	Vertex* tmp = endVertex;
	char* path[MAX_SIZE];

	while (strcmp(tmp->value, startVertex->value) != 0) {
		path[i++] = tmp->value;
		distance++;
		if (distance > 6 && flag == TRUE) {
			return -1;
		}

		tmp = graph_get_vertex(graph, tmp->parent);
	}
	
	path[i] = startVertex->value;
	return --distance;
}
