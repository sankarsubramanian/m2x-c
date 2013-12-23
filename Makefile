CC=clang
CFLAGS=-O0 -g -Wall -Wextra -std=c89
LDFLAGS=-lcurl

client.o: client.c client.h
	$(CC) -o $@ $(CFLAGS) -c $<

parson.o: third_party/parson/parson.c third_party/parson/parson.h
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm -rf *.o

.PHONY: clean
