// create a file

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd = open("out", O_RDWR | O_CREAT | O_TRUNC);
    char* content = "asdasdas\n";
    printf("fd=%d; content=%s\n", fd, content);
    write(fd, content, strlen(content));
    exit(0);
}
