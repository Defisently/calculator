CC = gcc
CFLAGS = -g

all: main tests

main: main.o io.o calc_operations.o
	$(CC) $(CFLAGS) -o main main.o io.o calc_operations.o

tests: tests.o calc_operations.o
	$(CC) $(CFLAGS) -o tests tests.o calc_operations.o

main.o: src/main.c
io.o: src/io.c input/io.h input/calc_operations.h
calc_operations.o: src/calc_operations.c input/calc_operations.h
tests.o: src/tests.c input/calc_operations.h main.o

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main tests
