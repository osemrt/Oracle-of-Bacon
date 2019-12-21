#include "../inc/main.h"

void linkedlist_init(linkedlist* l)
{
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
}

void linkedlist_insert_front(linkedlist* l, void* val)
{
	linkedlist_node* node;
	node = (linkedlist_node*)my_malloc(LINKED_LIST_NODE, 1);

	// list:
	//  [head node]->[node]->[node]->[tail node]
	// ^ inserting here

	node->next = l->head;
	node->prev = NULL;
	node->val = val;

	l->head = node;
	++l->size;
}

void linkedlist_insert_back(linkedlist* l, void* val)
{
	linkedlist_node* node;
	node = (linkedlist_node*)my_malloc(LINKED_LIST_NODE, 1);

	// list:
	//  [head node]->[node]->[node]->[tail node]
	//                                          ^ inserting here

	node->next = NULL;
	node->prev = l->tail;
	node->val = val;

	l->tail = node;
	++l->size;
}

void linkedlist_remove_node(linkedlist* l, linkedlist_node* node)
{

	linkedlist_node* n = l->head;

	while (n != node) {
		n = n->next;
	}
	assert(n == node);

	// erasing head node
	if (node == l->head)
		l->head = node->next;

	// erasing tail node
	if (node == l->tail)
		l->tail = node->prev;

	// updating pointers
	if (node->prev != NULL)
		((linkedlist_node*)node->prev)->next = node->next;

	if (node->next != NULL)
		((linkedlist_node*)node->next)->prev = node->prev;


	free(node);		

	// reduce size by one
	--l->size;
}

// this is a slow way of removal as it involves iterating, we should do this elsewhere. (it's O(N))
void linkedlist_remove_val(linkedlist* l, void* val)
{
	linkedlist_node* n, * n2;
	for (n = l->head; n != NULL; )
	{
		n2 = n;
		n = n->next;
		if (val == n2->val)
			linkedlist_remove_node(l, n2);
	}
}

// delete all elements
void linkedlist_clear(linkedlist* l)
{
	linkedlist_node* n, * n2;

	// lets do this in reverse order
	for (n = l->tail; n->prev != NULL; )
	{
		n2 = n;
		n = n->prev;

		free(n2);
	}

	l->head = l->tail = NULL;
	l->size = 0;
}

linkedlist_node* linkedlist_begin(linkedlist* l)
{
	return l->head;
}

linkedlist_node* linklist_end(linkedlist* l)
{
	return l->tail;
}

int linkedlist_size(linkedlist* l)
{
	return l->size;
}
