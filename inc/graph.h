#ifndef GRAPH_H
#define GRAPH_H

#include "linkedList.h"
#include "graph.h"
#include "my_malloc.h"


#define MAX_VERTEX_COUNT 300000
#define MOVIE 1
#define ACTOR 0

typedef struct Vertex {
	char* value;
	linkedlist* edges;
	int visited;
	char* parent;
	int type;
}Vertex;


typedef struct Graph {
	Vertex* vertices[MAX_VERTEX_COUNT];
	int size;
}Graph;

Graph* graph_create();
Vertex* graph_get_vertex(Graph* graph, char* str);
int graph_add_vertex(Graph* graph, Vertex* vertex);
Vertex* createVertex(char* value, int type);
void resetGraph(Graph* graph);

#endif // !GRAPH_H