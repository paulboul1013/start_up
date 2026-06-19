

CFLAGS= -Wall -Wextra -g -std=c99 -pedantic -Ithird_party_lib 
LDLIBS = -lm
OBJS= main.c time_parse.c timer.c 
.PHONY: all
all: main png2c penger_walk_sheet.h digits.h


main: $(OBJS) digits.h penger_walk_sheet.h
	$(CC) $(CFLAGS) -o main $(OBJS) $(LDLIBS)


png2c: png2c.c
	$(CC) $(CFLAGS) -o png2c png2c.c $(LDLIBS)

penger_walk_sheet.h: png2c penger_walk_sheet.png
	./png2c penger_walk_sheet.png penger > penger_walk_sheet.h

digits.h: png2c digits.png
	./png2c digits.png digits > digits.h

clean:
	rm -f main png2c penger_walk_sheet.h digits.h

