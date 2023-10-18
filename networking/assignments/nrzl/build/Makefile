CC = gcc
SOURCES = nrzl.c main.c 
STRING_SOURCE = ../../c_utils/string/string.c
OBJECTS = nrzl.o main.o string.o
BINARY = a.exe
SAMPLES_PER_BIT = 10

all: $(BINARY)

$(BINARY): $(OBJECTS)
	gcc $(OBJECTS) -o $(BINARY)

string.o: 
	gcc -c $(STRING_SOURCE)

%.o: ../%.c
	gcc -c $^ -D NUM_SAMPLES_PER_BIT=$(SAMPLES_PER_BIT)

clean:
	rm *.o
	rm $(BINARY)
