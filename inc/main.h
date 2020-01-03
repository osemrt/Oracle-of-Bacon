#ifndef MAIN_H
#define MAIN_H

#include "common.h"
#include "my_malloc.h"
#include "graph.h"
#include "hashTable.h"
#include "queue.h"

unsigned long long int stringToKey(char* str);
char* getFileFromUser(int* fileSize);
int hash(unsigned long long int key, int i);
unsigned long long int hash1(unsigned long long int key);
int hash2(unsigned long long int key);
int getNameFromFile(char* file, int filesize, int* i, char buffer[]);
void parseFile(char* file, int fileSize);
char* releaseUnusedSpace(char* str);
int computeDistance(char* actor1, char* actor2, char* path[], int flag);
int backtrace(struct Vertex* startVertex, struct Vertex* endVertex, char* path[], int flag);
void printResults(char* start, char* end, char* path[], int distance);
void showMenu();
char* readNameFromUser();

#endif // !MAIN_H

