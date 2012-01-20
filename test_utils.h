#ifndef TEST_UTILS_H_GUARD
#define TEST_UTILS_H_GUARD

#include <stdbool.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define assert_true(x) assert(x)
#define assert_false(x) assert(!x)
#define assert_string_equals(x, y) assert_true(strcmp((x), (y)) == 0)
#define assert_is_null(x) assert_true((x) == NULL)

void show_success_message();

void run_test(void(*function)());

#endif
