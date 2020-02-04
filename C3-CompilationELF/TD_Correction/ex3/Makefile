CC?=gcc
AR?=ar
all: 

setup: include/mylib.h
	mkdir -p ./build/lib
	mkdir -p ./build/include
	cp -r include ./build/

lib: setup lib/lib.c
	$(CC) -shared -fPIC -o build/lib/libcustom.so lib/lib.c -ldl

prog: main.c setup
	$(CC) -o build/test $<

run: lib prog
	LD_LIBRARY_PATH=./build/lib ./build/test

clean:
	rm -rf build/*
