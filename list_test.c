#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#define assert_true(x) assert(x)
#define assert_false(x) assert(!x)
#define assert_string_equals(x, y) assert_true(strcmp((x), (y)) == 0)
#define assert_is_null(x) assert_true((x) == NULL)

void empty_at_creation() {
	List *empty_list = new_List();
	
	assert_true(list_is_empty(empty_list));
	assert_true(list_size(empty_list) == 0);
	
	list_destroy(empty_list);
}

void not_empty_when_it_holds_one_element() {
	List *list = new_List();
	
	list_add(list, "Hello");
	
	assert_false(list_is_empty(list));
	assert_true(list_size(list) == 1);
	
	list_destroy(list);
}

void retrieve_elements() {
	List *list = new_List();
	
	char* element_1 = "Hello";
	char* element_2 = "brave";
	char* element_3 = "wolrd";
	
	list_add(list, element_1);
	list_add(list, element_2);
	list_add(list, element_3);
	
	assert_string_equals(list_at(list, 0), element_1);
	assert_string_equals(list_at(list, 1), element_2);
	assert_string_equals(list_at(list, 2), element_3);
	
	list_destroy(list);
}

void retrieve_null_if_position_does_not_exists() {
	List *list = new_List();
	
	assert_is_null(list_at(list, 0));
	
	list_destroy(list);
}

void show_success_message() {
	printf("\nALL TESTS PASS!!\n");
}

void run_test(void (*function)()) {
	function();
	printf(".");
}

int main() {
	run_test(empty_at_creation);
	run_test(not_empty_when_it_holds_one_element);
	run_test(retrieve_elements);
	run_test(retrieve_null_if_position_does_not_exists);
	
	show_success_message();	
}

