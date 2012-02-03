#include <stddef.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

bool is_empty(List* self) {
	return self->size == 0;
}

List* add(List *self, void* element) {
	ListNode* new_node = new_ListNode(element);

	if (self->last == NULL) {
		self->first = new_node;
		self->last = new_node;
	} else {
		ListNode* old_last = self->last;
		old_last->next = new_node;
		new_node->previous = old_last;
		self->last = new_node;
	}

	self->size = self->size + 1;

	return self;
}

ListNode* node_at(List* self, int position) {
	ListNode* currentNode = self->first;
	int i = 0;

	while (currentNode != NULL) {
		if (i == position) {
			return currentNode;
		}
		currentNode = currentNode->next;
		i++;
	}

	return NULL;
}

void* at(List* self, int position) {
	ListNode* node_at_position = node_at(self, position);
	return node_at_position != NULL ? node_at_position->element : NULL;
}

void previous_node_point_next_to(List* self, ListNode* previous_node, ListNode* new_next_node) {
	if (new_next_node != NULL && previous_node != NULL) {
		previous_node->next = new_next_node;
	}

	if (new_next_node == NULL) {
		self->last = previous_node;
	}

	if (previous_node == NULL) {
		self->first = new_next_node;
	}
}

void next_node_point_previous_to(List* self, ListNode* next_node, ListNode* new_previous_node) {
	assert(false && "Not implemented yet");
}

void remove_element_at(List* self, int position) {
	if (list_size(self) == 0) {
		return;
	}

	ListNode* node_to_remove = node_at(self, position);

	previous_node_point_next_to(self, node_to_remove->previous, node_to_remove->next);
	next_node_point_previous_to(self, node_to_remove->next, node_to_remove->previous);

	self->size = self->size - 1;
	free(node_to_remove);
}

void destroy(List* self) {
	ListNode* currentNode = self->first;

	while (currentNode != NULL) {
		ListNode* nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}

	free(self);
}

void bind_methods(List* list) {
	list->is_empty = is_empty;
	list->add = add;
	list->at = at;
	list->remove_element_at = remove_element_at;
	list->destroy = destroy;
}

void init(List* self) {
	self->first = NULL;
	self->last = NULL;
	self->size = 0;
}

List* new_List() {
	List *new_list = malloc(sizeof(List));

	bind_methods(new_list);
	init(new_list);

	return new_list;
}

ListNode* new_ListNode(void* element) {
	ListNode *new_list_node = malloc(sizeof(ListNode));

	new_list_node->element = element;
	new_list_node->next = NULL;
	new_list_node->previous = NULL;

	return new_list_node;
}

/* Simplified API */bool list_is_empty(List* self) {
	return self->is_empty(self);
}

List* list_add(List* self, void* element) {
	return self->add(self, (ListNode*) element);
}

int list_size(List* self) {
	return self->size;
}

void* list_at(List* self, int position) {
	return self->at(self, position);
}

void list_remove_element_at(List* self, int position) {
	return self->remove_element_at(self, position);
}

void list_destroy(List* self) {
	self->destroy(self);
}

//assert(false && "Not implemented yet");
