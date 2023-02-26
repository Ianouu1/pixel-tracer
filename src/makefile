CC=gcc
CFLAGS=-W -Wall -pedantic
LDFLAGS=
EXEC=draw
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

draw: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)



.PHONY: clean mrproper

clean:
	rm -rf *.o
	rm draw
mrproper: clean
	rm -rf $(EXEC)
