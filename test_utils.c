#include "test_utils.h"
#include <stdio.h>

int test_count = 0;

void show_success_message() {
	printf("\nALL (%d) TESTS PASS!!\n", test_count);
}

void run_test(void(*function)()) {
	function();
	test_count++;
	printf(".");
}
