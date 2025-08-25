// fork then exec

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid, status;

    pid = fork();
    if (pid == 0) {
        char *argv[] = { "echo", "THIS", "IS", "ECHO", 0 };
        execvp("echo", argv);
        printf("exec failed!\n");
    } else {
        printf("parent waiting\n");
        wait(&status);
        printf("the child exited with status %d\n", status);
    }

    exit(0);
}
