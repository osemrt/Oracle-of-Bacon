#include "../inc/main.h"

int backtrace(Vertex* startVertex, Vertex* endVertex, Stack* stack, int flag) {

	int distance = 0;
	Vertex* tmp = endVertex;

	while (strcmp(tmp->value, startVertex->value) != 0) {
		push(stack, tmp->value);
		if (tmp->type == MOVIE) {
			distance++;
		}
		if (distance > 6 && flag == TRUE) {
			return -1;
		}

		tmp = graph_get_vertex(graph, tmp->parent);
	}

	push(stack, startVertex->value);
	return distance;
}
