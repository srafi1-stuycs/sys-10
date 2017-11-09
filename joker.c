#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sig_handler(int signo) {
    if (signo == SIGINT) {
        char msg[] = "Would you look at that. It's a SIGINT\n";
        int fd = open("joker.log", O_CREAT | O_WRONLY | O_APPEND, 0600);
        write(fd, msg, sizeof(msg));
        close(fd);
        printf("Closing and writing to joker.log\n");
        exit(SIGINT);
    } else if (signo == SIGUSR1) {
        printf("Parent PID: %d dares to try and end me\n", getppid());
    }
}

int main() {
    signal(SIGINT, sig_handler);
    signal(SIGUSR1, sig_handler);
    while (1) {
        printf("Process id: %d\n", getpid());
        sleep(1);
    }
    return 0;
}
