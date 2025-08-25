// redirect the output of a command

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid;

    pid = fork();
    
    if (pid == 0) {
        close(1);
        open("out", O_WRONLY | O_CREAT | O_TRUNC);

        char *argv[] = { "echo", "THIS", "IS", "ECHO", 0 };
        execvp("echo", argv);

        printf("exec failed!\n");
    } else {
        printf("parent waiting\n");
        wait((int *) 0);
    }

    exit(0);
}
