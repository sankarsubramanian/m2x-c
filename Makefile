AR=ar
CC=gcc
CFLAGS=-O2 -Wall -Wextra -std=c89
LDFLAGS=-lcurl
M2X_LIB=m2x.a

OBJS=device.o distribution.o key.o timestamp.o chart.o response.o client.o serializer.o utility.o m2x.o collection.o job.o command.o
$(M2X_LIB): $(OBJS) parson.o
	$(AR) -rcs $@ $^

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $<

parson.o: third_party/parson/parson.c third_party/parson/parson.h
	$(CC) -o $@ $(CFLAGS) -c $<

include Makefile.dep

dep:
	$(CC) -MM *.c > Makefile.dep

examples:
	cd examples; make

clean:
	cd examples; make clean
	rm -rf $(M2X_LIB) *.o

.PHONY: clean examples dep
