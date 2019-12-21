#ifndef HASHTABLE_H
#define HASHTABLE_H


enum entryStatus { EMPTY, DELETED, OCCUPIED };

typedef struct HashNode {
	int key;
	int value;
}HashNode;

typedef struct Entry {
	struct HashNode* hashNode;
	enum entryStatus status;
}Entry;

typedef struct HashTable {
	int size;
	struct Entry* arr;
}HashTable;

HashTable* ht_create(int size);
Entry* ht_search(HashTable* hashTable, unsigned long long int key);
void ht_put(HashTable* hashTable, unsigned long long int key, int value);
int ht_get(HashTable* hashTable, unsigned long long int key);
int ht_delete(HashTable* hashTable, int key);
void ht_print(HashTable* hashTable);


#endif // !HASHTABLE_H