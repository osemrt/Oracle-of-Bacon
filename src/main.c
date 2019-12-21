#include "../inc/main.h"

int main(int argc, char const* argv[])
{
	hashTable = ht_create(MAX_VERTEX_COUNT * 2);
	graph = graph_create();

	FILE* fp = getFileFromUser();
	parseFile(fp);

	ht_print(hashTable);
	Vertex* vertex = graph_get_vertex(graph, "Cobra (1986)");

	linkedlist* list = vertex->edges;

	while (list->head!=NULL)
	{
		printf("%s", list->head->val);
		list->head = list->head->next;

	}



	return 0;
}
