CC := gcc
LD := $(CC)
CFLAGS := -Wall\
		  -Werror\
 		  -pedantic

build/test: build build/test.o
	$(LD) $(CFLAGS) build/test.o -o build/test

build/test.o: test/test.c test/test.h src/returnif.h
	$(LD) $(CFLAGS) -c test/test.c -o build/test.o

build:
	mkdir build

.PHONY: test
test: build/test
	cd ./build && ./test

default: build/test
