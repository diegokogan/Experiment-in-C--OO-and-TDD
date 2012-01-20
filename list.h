#ifndef LIST_H_GUARD
#define LIST_H_GUARD

#include <stdbool.h>

typedef struct ListNode {
	struct ListNode* next;
	struct ListNode* previous;
	void* element;
} ListNode;

typedef struct List {
	/* instance variables */
	ListNode* first;
	ListNode* last;
	int size;

	/* methods */
	bool (*is_empty)(struct List *self);
	struct List* (*add)(struct List *self, void* element);
	void* (*at)(struct List *self, int position);
	void (*destroy)(struct List *self);
} List;

/* Creation */
List *new_List();
ListNode* new_ListNode(void* element);

/* Simpified API */
bool list_is_empty(List* self);
List* list_add(List* self, void* element);
int list_size(List* self);
void* list_at(List* self, int position);

/* destruction */
void list_destroy(List* self);

#endif
