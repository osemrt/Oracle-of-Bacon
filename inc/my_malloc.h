#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include "queue.h"
#include "linkedList.h"
#include "graph.h"
#include "hashTable.h"

//All constants in the below
//are used in createArrayFromHeap()
//to do not deal with malloc() return value
//if it returns NULL.
#define INT 0
#define CHAR 1
#define STRING 2
#define LINKED_LIST 3
#define LINKED_LIST_NODE 4
#define GRAPH 5
#define VERTEX 6
#define ENTRY 7
#define HASH_TABLE 8
#define HASH_NODE 9
#define KEY 10
#define QUEUE 11
#define STACK 12

void* my_malloc(int TYPE, int size);

#endif // !MY_MALLOC_H