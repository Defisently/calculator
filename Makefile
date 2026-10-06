CC = gcc
CFLAGS = -g

all: main tests

main: main.o io.o calc_operations.o
	$(CC) $(CFLAGS) -o main main.o io.o calc_operations.o

tests: tests.o calc_operations.o
	$(CC) $(CFLAGS) -o tests tests.o calc_operations.o

main.o: src/main.c include include
io.o: src/io.c include include
calc_operations.o: src/calc_operations.c include
tests.o: src/tests.c include main.o

%.o: src/%.c
	$(CC) -I./include $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main tests
