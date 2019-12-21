#include "../inc/main.h"

int main(int argc, char const* argv[])
{
	hashTable = ht_create(MAX_VERTEX_COUNT * 2);
	graph = graph_create();

	int fileSize;
	char* file = getFileFromUser(&fileSize);
	parseFile(file, fileSize);
	Stack* stack = createStack();

	char *actor1 = "Schwarzenegger, Arnold";
	char *actor2 = "Streep, Meryl";
	int distance = computeDistance(actor1, actor2, stack, FALSE);

	printResults(actor1, actor2, stack, distance);




	return 0;
}
