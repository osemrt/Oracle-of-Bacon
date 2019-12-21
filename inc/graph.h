#ifndef GRAPH_H
#define GRAPH_H

#include "linkedList.h"

#define MAX_VERTEX_COUNT 30000

typedef struct Vertex {
	char* value;
	linkedlist* edges;
	int visited;
	char* parent;
}Vertex;


typedef struct Graph {
	Vertex* vertices[MAX_VERTEX_COUNT];
	int size;
}Graph;

Graph* graph_create();
Vertex* graph_get_vertex(Graph* graph, char* str);
int graph_add_vertex(Graph* graph, Vertex* vertex);
Vertex* createVertex(char* value);

#endif // !GRAPH_H