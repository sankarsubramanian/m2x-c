CC=clang
CFLAGS=-O0 -g -Wall -Wextra -std=c89 -I..
LDFLAGS=-lcurl
M2X_LIB=../m2x.a

all: m2x_status

m2x_status: m2x_status.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

m2x_status.o: m2x_status.c
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm -rf m2x_status *.o

.PHONY: all clean
