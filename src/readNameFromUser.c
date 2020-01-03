#include "main.h"

//A function to read a actor name from the user
char* readNameFromUser() {
	char input[MAX_SIZE];
	int c;
	Vertex* vertex;
	do {
		printf("Type an actress or actor: ");
		fgets(input, MAX_SIZE, stdin);
		input[strlen(input) - 1] = '\0';
		vertex = graph_get_vertex(graph, input);
		if (vertex == NULL) {
			clearScreen();
			printf("Could not find!\n");
		}
	} while (vertex == NULL);

	char* result = releaseUnusedSpace(input);

	return result;
}