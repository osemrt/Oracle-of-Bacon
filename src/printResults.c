#include "..\inc\main.h"

void printResults(char* start, char* end, Stack* stack, int distance) {
	printf("%s | %s: %d\n", start, end, distance);
	
	char* actor1;
	char* actor2;
	char* movie;

	int i = 0;
	while (_isEmpty(stack) != TRUE && i<distance) {
		pop(stack, &actor1);
		pop(stack, &movie);
		pop(stack, &actor2);
		push(stack, actor2);

		printf("%s - %s \"%s\"\n", actor1, actor2, movie);
		i++;
	}

	resetStack(stack);

}