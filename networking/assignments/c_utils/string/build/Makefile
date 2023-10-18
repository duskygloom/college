CC = gcc
BINARY = a.exe
OBJECTS = string.o main.o

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARY)

$(OBJECTS): ../string.c ../main.c
	$(CC) -c $^

clean:
	rm *.o
	rm $(BINARY)
