CC = gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)

#CFLAGS = -c -Wall -I

SRCS = bodyelement.c createDom.c docparse.c function.c headelement.c main.c# and so on...
OBJS = bodyelement.o createDom.o docparse.o function.o headelement.o main.o# and so on...

all: main.out
%.o: %.c
	$(CC) -c -o $(@F) $(CFLAGS) $<

main.out: $(OBJS)
	$(CC) -o $(@F) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)
	rm -f main.out






