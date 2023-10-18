CC = gcc
OBJECTS = tree.o bst.o main.o
BINARY = a.exe

all: $(BINARY)

$(BINARY): $(OBJECTS) 
	$(CC) -o $(BINARY) $(OBJECTS)

$(OBJECTS): ../../tree.c ../bst.c ../main.c
	$(CC) -c $^

clean:
	rm *.o
	rm $(BINARY)
