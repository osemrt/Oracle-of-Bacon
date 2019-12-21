#include "../inc/main.h"

//A function to allocate memory in the heap in the desired manner
//and if it is not created then it ends the program
void* my_malloc(int TYPE, int size) {

	void* arr;
	switch (TYPE)
	{
	case INT:
		arr = malloc(sizeof(int) * size);
		break;
	case CHAR:
		arr = malloc(sizeof(char) * size);
		break;
	case STRING:
		arr = malloc(sizeof(char*) * size);
		break;
	case LINKED_LIST:
		arr = malloc(sizeof(linkedlist) * size);
		break;
	case LINKED_LIST_NODE:
		arr = malloc(sizeof(linkedlist_node) * size);
		break;
	case GRAPH:
		arr = malloc(sizeof(Graph) * size);
		break;
	case VERTEX:
		arr = malloc(sizeof(Vertex) * size);
		break;

	/*case ENTRY:
		arr = (Entry*)malloc(sizeof(Entry) * size);
		break;

	case HASH_TABLE:
		arr = (HashTable*)malloc(sizeof(HashTable) * size);
		break;

	case HASH_NODE:
		arr = (HashNode*)malloc(sizeof(HashNode) * size);
		break;

	case REGULAR_FILE:
		arr = (File*)malloc(sizeof(File) * size);
		break;*/

	default:
		arr = (void*)malloc(size);
		break;
	}

	if (arr == NULL) {
		printf("An error has occurred while creating the array!\n");
		exit(1);
	}

	return arr;

}