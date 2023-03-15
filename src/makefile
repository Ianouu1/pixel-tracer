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


win:
	x86_64-w64-mingw32-gcc *.c -I"../readline/include/" -L"../readline/lib/" -lreadline -o draw.exe

.PHONY: clean mrproper

indent:
	indent -kr -brf -as -nut -ppi 2 *.c *.h

clean:
	rm -rf *.o
	rm draw
mrproper: clean
	rm -rf $(EXEC)
