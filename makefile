CC = gcc 
CFLAGS = -std=c99 -Wall -ggdb
COMPILE = $(CC) $(CFLAGS) 

all: list_test.c list.c test_utils.c
	$(COMPILE) list_test.c list.c test_utils.c 

	
run_tests: list_test.o list.o test_utils.o
	$(COMPILE) list_test.o list.o test_utils.o  && ./a.out

	
clean:
	rm -f *.out *.o

	
	
	
