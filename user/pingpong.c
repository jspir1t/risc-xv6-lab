#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int
main(int argc, char* argv[]) {

    int p[2];
    char buf[1];
    pipe(p);

    int pid = fork();
    if (pid < 0) {
        fprintf(2, "Process Fork Error!");
    } else if (pid == 0) {
        // child process
        read(p[0], buf, sizeof(buf));
        close(p[0]);
        printf("%d: received ping\n", getpid());

        write(p[1], "C", 1);
        close(p[1]);
    } else {
        // parent process
        write(p[1], "P", 1);
        close(p[1]);

        read(p[0], buf, sizeof(buf));
        close(p[0]);
        printf("%d: received pong\n", getpid());
    }
    exit(0);
}