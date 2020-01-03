#include "main.h"

//A function to reset the graph after each querying operations
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