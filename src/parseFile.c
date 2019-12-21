#include "../inc/main.h"

void parseFile(char* file, int fileSize) {

	char* movie = NULL;
	char* actor = NULL;
	Vertex* movie_vertex = NULL;
	Vertex* actor_vertex = NULL;
	char buffer[MAX_SIZE];
	char ch = '\0';

	int i = 0;
	while (i < fileSize) {
		ch = getNameFromFile(file, fileSize, &i, buffer);


		movie = releaseUnusedSpace(buffer);
		movie_vertex = createVertex(movie, MOVIE);
		graph_add_vertex(graph, movie_vertex);

		if (strcmp("Villain, The (1979)", movie) == 0) {
			printf("asd");
		}


		if (ch == '/') {
			printf("Adding actors/actresses played on '%s' to the graph...\n", movie);
			while (ch != '\n' && i < fileSize) {
				ch = getNameFromFile(file, fileSize, &i, buffer);
				if (ch == '/' || ch == '\n') {
					actor = releaseUnusedSpace(buffer);


					if (strcmp("Schwarzenegger, Arnold", actor) == 0) {
						printf("123");
					}

					actor_vertex = graph_get_vertex(graph, actor);
					if (actor_vertex == NULL) {
						actor_vertex = createVertex(actor, ACTOR);
						graph_add_vertex(graph, actor_vertex);
					}

					linkedlist_insert_back(movie_vertex->edges, actor);
					linkedlist_insert_back(actor_vertex->edges, movie);
				}

			}
			printf("Adding the cast of '%s' is completed...\n\n", movie);

		}
	}
}