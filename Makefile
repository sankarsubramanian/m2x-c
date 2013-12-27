AR=ar
CC=clang
CFLAGS=-O0 -g -Wall -Wextra -std=c89
LDFLAGS=-lcurl
M2X_LIB=m2x.a

$(M2X_LIB): feed.o blueprint.o m2x.o client.o parson.o
	$(AR) -rcs $@ $^

feed.o: feed.c m2x.h client.h feed.h third_party/parson/parson.h
	$(CC) -o $@ $(CFLAGS) -c $<

blueprint.o: blueprint.c m2x.h client.h blueprint.h third_party/parson/parson.h
	$(CC) -o $@ $(CFLAGS) -c $<

m2x.o: m2x.c m2x.h
	$(CC) -o $@ $(CFLAGS) -c $<

client.o: client.c client.h m2x.h
	$(CC) -o $@ $(CFLAGS) -c $<

parson.o: third_party/parson/parson.c third_party/parson/parson.h
	$(CC) -o $@ $(CFLAGS) -c $<

examples:
	cd examples; make

clean:
	cd examples; make clean
	rm -rf $(M2X_LIB) *.o

.PHONY: clean examples
