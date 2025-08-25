#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int fds[2]; // from pipe()
    char buf[100]; // buffer to communicate
    int n;

    pipe(fds);
    
    write(fds[1], "xyz\n", 4);

    n = read(fds[0], buf, sizeof(buf));

    write(1, buf, n);
   
    exit(0);
}
