// replace a process with an executable file

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char* argv[] = { "echo", "this", "is", "echo", NULL };

  execvp("echo", argv);

  printf("exec failed!\n");

  exit(0);
}
