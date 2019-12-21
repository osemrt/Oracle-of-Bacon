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

#define TRUE 1
#define FALSE 0

#define FOUND 1
#define NOT_FOUND 0

#define MAX_SIZE 512

//A constant used in stringToKey()
//to calculate the key of a string
#define PRIME 31

unsigned long long int stringToKey(char* str);
FILE* getFileFromUser();
int hash(unsigned long long int key, int i);
unsigned long long int hash1(unsigned long long int key);
unsigned long long int hash2(unsigned long long int key);
int probe(HashTable* hashTable, unsigned long long int key);
char getNameFromFile(FILE* fp, char buffer[]);
int parseFile(FILE* fp);
char* releaseUnusedSpace(char* str);


HashTable* hashTable;
Graph* graph;



#endif // !MAIN_H

