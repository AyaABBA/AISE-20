#include <stdlib.h>
#include <stdio.h>
int main() {
  int var, check = 0x04030201;
  char buf[40];

  fgets(buf,45,stdin);

  printf("buf = %s\n", buf);
  printf("check = 0x%x\n", check);

  if (check == 0xdeadbeef) {
       printf("You Win !\n");
       system("/bin/sh");
     }
   return 0;
}

