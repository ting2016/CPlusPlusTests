INCLUDE_DIR := .
a : main.o lib.o
	cc -o a main.o lib.o

main.o: main.c $(INCLUDE_DIR)/lib.h
	cc -c main.c

lib.o : lib.c $(INCLUDE_DIR)/lib.h
	cc -c lib.c

