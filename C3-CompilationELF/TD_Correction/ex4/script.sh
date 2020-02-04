#!/bin/bash

file=${1//\.c/}
cpp $file.c > $file.i
/usr/lib/gcc/x86_64-linux-gnu/6/cc1 $file.i -o $file.s # add -fPIC here for library
as $file.s -o $file.o
ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 $file.o /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/x86_64-linux-gnu/crtn.o /usr/lib/x86_64-linux-gnu/crt1.o -lc # remove crt1.o for shared and add 'shared' for libraries
