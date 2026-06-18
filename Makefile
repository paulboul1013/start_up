

CFLAGS= -Wall -Wextra -g -std=c99 -pedantic -Ithird_party_lib 
LDLIBS = -lm
.PHONY: all
all: main png2c penger_walk_sheet.h


main: main.c
	$(CC) $(CFLAGS) -o main main.c $(LDLIBS)


png2c: png2c.c
	$(CC) $(CFLAGS) -o png2c png2c.c $(LDLIBS)

penger_walk_sheet.h: png2c penger_walk_sheet.png
	./png2c penger_walk_sheet.png penger > penger_walk_sheet.h

clean:
	rm -f main png2c penger_walk_sheet.h

