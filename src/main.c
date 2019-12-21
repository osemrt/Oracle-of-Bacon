#include "../inc/main.h"

int main(int argc, char const* argv[])
{
	hashTable = ht_create(MAX_VERTEX_COUNT * 2);
	graph = graph_create();

	FILE* fp = getFileFromUser();
	parseFile(fp);
	char path[MAX_SIZE];

	int distance = computeDistance("Adcock, Danny", "Barnes, Deryck", FALSE);

	Vertex* vertex = graph_get_vertex(graph, "Inferno (2000)");


	return 0;
}
