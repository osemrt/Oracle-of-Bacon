#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "graph.h"
#include "hashTable.h"
#include "linkedList.h"
#include "queue.h"
#include "my_malloc.h"s
#include "stack.h"s

#define TRUE 1
#define FALSE 0

#define FOUND 1
#define NOT_FOUND 0

#define MAX_SIZE 512

//A constant used in stringToKey()
//to calculate the key of a string
#define PRIME 31

unsigned long long int stringToKey(char* str);
char* getFileFromUser(int* fileSize);
int hash(unsigned long long int key, int i);
unsigned long long int hash1(unsigned long long int key);
int hash2(unsigned long long int key);
int getNameFromFile(char* file, int filesize, int* i, char buffer[]);
void parseFile(char* file, int fileSize);
char* releaseUnusedSpace(char* str);
int computeDistance(char* actor1, char* actor2, Stack* stack, int flag);
int backtrace(Vertex* startVertex, Vertex* endVertex, Stack* stack, int flag);
void printResults(char* start, char* end, Stack* stack, int distance);
void showMenu();
char* readNameFromUser();

HashTable* hashTable;
Graph* graph;



#endif // !MAIN_H

