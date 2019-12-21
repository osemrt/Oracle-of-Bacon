#include "../inc/main.h"

Graph* graph_create() {
	Graph* graph = (Graph*)my_malloc(GRAPH, 1);
	graph->size = 0;
	return graph;
}

Vertex* graph_get_vertex(Graph* graph, char* str) {
	unsigned long long int key = stringToKey(str);
	int index = ht_get(hashTable, key);
	if (index >= graph->size)
		return NULL;

	return graph->vertices[index];
}

int graph_add_vertex(Graph* graph, Vertex* vertex) {
	unsigned long long int key = stringToKey(vertex->value);
	int index = ht_get(hashTable, key);
	if (index != INT_MIN) {
		index = graph->size;
		ht_put(hashTable, key, index);
		graph->vertices[index] = vertex;
		graph->size++;
	}

	return TRUE;

}

Vertex* createVertex(char* value) {
	Vertex* vertex = (Vertex*)my_malloc(VERTEX, 1);
	vertex->value = value;
	linkedlist_init(vertex->edges);
	vertex->visited = FALSE;
	vertex->parent = NULL;
}