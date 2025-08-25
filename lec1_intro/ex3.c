// fork

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
    int pid;

    pid = fork();

    if(pid == 0){
        printf("current pid = %d; child pid = %d child\n", getpid(), pid);

        pid = fork();
        printf("current pid = %d; child pid = %d child\n", getpid(), pid);
    } else {
        printf("current pid = %d; child pid = %d parent\n", getpid(), pid);
    }
  
  exit(0);
}
