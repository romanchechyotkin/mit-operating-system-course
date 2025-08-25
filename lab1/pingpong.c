#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  int p[2];
  int pid, n;
  char b[1];

  // ping_pipe[1] -> ping_pipe[0] -> pong_pipe[1] -> pong_pipe[0]
  //  parent                     child                parent 
  pipe(p);
  
  pid = fork();
  if (pid == 0) {
    n = read(p[0], b, sizeof(b));
    if (n == 1) {
      printf("%d: received ping\n", getpid());
    } else {
      exit(1);
    }
    close(p[0]);
    write(p[1], b, n);
    close(p[1]);
  } else {
    write(p[1], b, 1);
    close(p[1]);
    wait(0);
    n = read(p[0], b, sizeof(b));
    if (n == 1) {
      printf("%d: received pong\n", getpid());
    } else {
      exit(1);
    }
    close(p[0]);
  }

  exit(0);
}
