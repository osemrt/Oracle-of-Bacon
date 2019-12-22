#include "../inc/main.h"

int main(int argc, char const* argv[])
{
	hashTable = ht_create(MAX_VERTEX_COUNT * 2);
	graph = graph_create();
	showMenu();

	return 0;
}
