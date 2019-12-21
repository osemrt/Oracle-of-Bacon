#include "../inc/main.h"

int parseFile(FILE* fp) {

	char* movie = NULL;
	char* actor = NULL;
	Vertex* movie_vertex = NULL;
	Vertex* actor_vertex = NULL;
	char buffer[MAX_SIZE];
	char ch = '\0';

	while (ch != EOF) {
		ch = getNameFromFile(fp, buffer);

		if (ch == '/') {
			movie = releaseUnusedSpace(buffer);
			movie_vertex = createVertex(movie);
			graph_add_vertex(graph, movie_vertex);
		}
		printf("Adding actors/actresses played on '%s' to the graph...\n", movie);
		while (ch != '\n' && ch != EOF) {
			ch = getNameFromFile(fp, buffer);
			if (ch == '/') {
				actor = releaseUnusedSpace(buffer);
				if (strcmp("NeverEnding Story II: The Next Chapter, The (1990)", movie) == 0) {
					printf("here!");
				}
				actor_vertex = createVertex(actor);
				graph_add_vertex(graph, actor_vertex);
				linkedlist_insert_front(movie_vertex->edges, actor);
				linkedlist_insert_front(actor_vertex->edges, movie);
			}

		}
		printf("Adding the cast of '%s' is completed...\n\n", movie);
		printf("%d", graph->size);
	}

	fclose(fp);

}