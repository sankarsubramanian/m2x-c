CC=gcc
CFLAGS=-O2 -Wall -Wextra -std=c89 -I..
LDFLAGS=-lcurl
M2X_LIB=../m2x.a

all: m2x_status read_feeds update_stream

update_stream: update_stream.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

update_stream.o: update_stream.c
	$(CC) -o $@ $(CFLAGS) -c $<

read_feeds: read_feeds.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

read_feeds.o: read_feeds.c
	$(CC) -o $@ $(CFLAGS) -c $<

m2x_status: m2x_status.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

m2x_status.o: m2x_status.c
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm -rf m2x_status read_feeds update_stream *.o

.PHONY: all clean
