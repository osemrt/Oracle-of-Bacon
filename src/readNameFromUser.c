#include "..\inc\main.h"

//A function to read a actor name from the user
char* readNameFromUser() {
	char input[MAX_SIZE];
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
	Vertex* vertex;
	do {
		printf("Type an actress or actor: ");
		fgets(input, MAX_SIZE, stdin);
		input[strlen(input) - 1] = '\0';
		vertex = graph_get_vertex(graph, input);
		if (vertex == NULL) {
			clearScreen();
			printf("Could not find!\n", input);
		}
	} while (vertex == NULL);

	char* result = releaseUnusedSpace(input);

	return result;
}