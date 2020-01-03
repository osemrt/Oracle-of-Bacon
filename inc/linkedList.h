#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct linkedlist_node
{	struct linkedlist_node* prev;
	struct linkedlist_node* next;
	char* val;
} linkedlist_node;

typedef struct linkedlist
{
	struct linkedlist_node* head;
	struct linkedlist_node* tail;
	int size;
} linkedlist;

void linkedlist_init(linkedlist* l);
void linkedlist_insert_front(linkedlist* l, char* val);
void linkedlist_insert_back(linkedlist* l, char* val);
void linkedlist_remove_node(linkedlist* l, linkedlist_node* node);
void linkedlist_remove_val(linkedlist* l, char* val);
void linkedlist_clear(linkedlist* l);
linkedlist_node* linkedlist_begin(linkedlist* l);
linkedlist_node* linklist_end(linkedlist* l);
int linkedlist_size(linkedlist* l);

#endif // !LINKEDLIST_H
