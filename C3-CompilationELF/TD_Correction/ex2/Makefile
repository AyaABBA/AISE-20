CC?=gcc
AR?=ar
all: 

setup: include/mylib.h
	mkdir -p ./build/libcustom ./build/libcustom2
	mkdir -p ./build/include
	cp -r include ./build/

%.so: lib/%.c setup
	$(CC) -shared -fPIC -o build/$(*F)/$@ $<
	$(CC) -shared -fPIC -o build/$(*F)/libcustom.so $<

build/test: main.c libcustom2.so libcustom.so setup
	$(CC) -I./build/include -L./build/libcustom -L./build/libcustom2 $< -lcustom -lcustom2 -o $@

build/test-rpath: main.c libcustom2.so libcustom.so setup
	$(CC) -I./build/include -L./build/libcustom -L./build/libcustom2 -Wl,-rpath=./build/libcustom -Wl,-rpath=./build/libcustom2 $< -lcustom -lcustom2 -o $@

run: build/test
	LD_LIBRARY_PATH=./build/libcustom:./build/libcustom2 ./build/test

run-rpath: build/test-rpath
	./build/test-rpath

clean:
	rm -rf build/*
