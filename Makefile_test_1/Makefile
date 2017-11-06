CC=gcc
CFLAGS=-I.
DEPS = func.h
OBJ = hellomake.o func.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
