#include "list.h"
#include "test_utils.h"

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
	char* element_3 = "World";

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

void remove_the_only_one_element() {
	List *list = new_List();

	list_add(list, "Hello");

	assert_true(list_size(list) == 1);

	list_remove_element_at(list, 0);

	assert_true(list_is_empty(list));

	list_destroy(list);
}

void remove_first_element_in_a_list_of_two() {
	List *list = new_List();

	char* second_element = "World";

	list_add(list, "Hello");
	list_add(list, second_element);

	assert_true(list_size(list) == 2);

	list_remove_element_at(list, 0);

	assert_true(list_size(list) == 1);
	assert_string_equals(list_at(list, 0), second_element);

	list_destroy(list);
}

int main() {
	run_test(empty_at_creation);
	run_test(not_empty_when_it_holds_one_element);
	run_test(retrieve_elements);
	run_test(retrieve_null_if_position_does_not_exists);
	run_test(remove_the_only_one_element);
	run_test(remove_first_element_in_a_list_of_two);

	show_success_message();
}

