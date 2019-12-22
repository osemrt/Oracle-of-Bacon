#include "..\inc\main.h"

void resetGraph(Graph* graph) {
	int size = graph->size;
	int i = 0;
	while (i < size) {
		if (graph->vertices[i] != NULL) {
			graph->vertices[i]->visited = FALSE;
		}
			i++;
	}
}