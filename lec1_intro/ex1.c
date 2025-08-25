// copy input to output

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define STDIN 0
#define STDOUT 1

int main() {
      char buf[64];

  while(1){
    int n = read(0, buf, sizeof(buf));
    printf("%d\n", n);
    if(n <= 0) {
      break;
    }

    write(1, buf, n);
  }

  exit(0);
}
