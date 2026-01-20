GCC=gcc
CFLAGS=-std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = sort
TESTFLAGS = -DASCENDING
TESTS = \
	testcases/input1 \
	testcases/input2 \
	testcases/input3

all: main.c sort.c
	$(GCC) $(CFLAGS) -o $(EXEC) main.c sort.c
	
# Fix the gcc command for the target ascending by fill in the missing part
ascending: main.c sort.c
	$(GCC) $(CFLAGS) -DASCENDING -o $(EXEC) main.c sort.c
	
test: all
	@for path in $(TESTS); do \
		./$(EXEC) $$path; \
	done

test-ascending: ascending
	@for path in $(TESTS); do \
		./$(EXEC) $$path; \
	done
	
clean:
	rm -f $(EXEC)
	rm -f *.o
