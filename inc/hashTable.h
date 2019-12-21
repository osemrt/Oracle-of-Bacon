#ifndef HASHTABLE_H
#define HASHTABLE_H


enum entryStatus { EMPTY, DELETED, OCCUPIED };

typedef struct Key {
	char* str;
	unsigned long long int value;
}Key;

typedef struct HashNode {
	Key* key;
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
Entry* ht_search(HashTable* hashTable, Key key);
void ht_put(HashTable* hashTable, Key key, int value);
int ht_get(HashTable* hashTable, Key key);
int ht_delete(HashTable* hashTable, Key key);
void ht_print(HashTable* hashTable);


#endif // !HASHTABLE_H