#include "graph.h"

Graph* graph_create() {
	Graph* graph = (Graph*)my_malloc(GRAPH, 1);
	graph->size = 0;
	return graph;
}

Vertex* graph_get_vertex(Graph* graph, char* str) {
	Key* key = (Key*)my_malloc(KEY, 1);
	key->str = str;
	key->value = stringToKey(str);


	int index = ht_get(hashTable, key);
	if (index == INT_MIN)
		return NULL;

	return graph->vertices[index];
}

int graph_add_vertex(Graph* graph, Vertex* vertex) {
	Key* key = (Key*)my_malloc(KEY, 1);
	key->str = vertex->value;
	key->value = stringToKey(vertex->value);

	int index = ht_get(hashTable, key);
	if (index == INT_MIN) {
		index = graph->size;
		graph->vertices[index] = vertex;
		ht_put(hashTable, key, index);
		graph->size++;
	}
	return TRUE;
}

Vertex* createVertex(char* value, int type) {
	Vertex* vertex = (Vertex*)my_malloc(VERTEX, 1);
	vertex->value = value;
	vertex->edges = (linkedlist*)my_malloc(LINKED_LIST, 1);
	linkedlist_init(vertex->edges);
	vertex->visited = FALSE;
	vertex->parent = NULL;
	vertex->type = type;
	return vertex;
}