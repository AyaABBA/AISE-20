CC?=gcc
AR?=ar
all: 

setup: include/mylib.h
	mkdir -p ./build/lib
	mkdir -p ./build/include
	cp -r include ./build/

lib: setup lib/lib.c
	$(CC) -fPIC -c -o build/lib/lib.o lib/lib.c
	$(CC) -shared -o build/lib/libcustom.so build/lib/lib.o
	$(AR) rcs build/lib/libcustom.a build/lib/lib.o

prog: setup main.c lib
	$(CC) -static -I./build/include -L./build/lib/ main.c -lcustom -o build/test-static
	$(CC) -I./build/include -L./build/lib/ main.c -lcustom -o build/test-dyn

prog-rpath: setup main.c lib
	$(CC) -I./build/include -L./build/lib/ -Wl,-rpath=./build/lib main.c -lcustom -o build/test-rpath

run: lib prog
	LD_LIBRARY_PATH=./build/lib ./build/test

run-rpath: lib prog-rpath
	./build/test-rpath

clean:
	rm -rf build/*
