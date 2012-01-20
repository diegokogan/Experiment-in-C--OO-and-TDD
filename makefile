CC = gcc 
CFLAGS = -std=c99 -Wall -ggdb
COMPILE = $(CC) $(CFLAGS) 

all: list_test.o list.o
	$(COMPILE) list_test.o list.o

run_tests: list_test.o list.o
	$(COMPILE) list_test.o list.o  && ./a.out

test.o: list_test.c list.c
	$(COMPILE) list_test.c list.c
	
	

clean:
	rm -f *.out *.o

	
	
	
