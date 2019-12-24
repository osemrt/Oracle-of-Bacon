#include "..\inc\main.h"

//A funtion to print the result after backtracking
void printResults(char* start, char* end, char* path[], int distance) {
	printf("\n\t%s ~ %s: %d\n", start, end, distance);
	printf("\t==========================\n");
	
	char* actor1;
	char* actor2;
	char* movie;

	int i = 0;

	while (path[i+1]!=NULL) {
		actor1 = path[i++];
		movie = path[i++];
		actor2 = path[i];


		printf("\t%s - %s {%s}\n", actor1, actor2, movie);
	}

}