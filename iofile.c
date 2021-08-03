
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "iofile.h"
#include <sys/types.h>
#include <unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024
char *url = "/home/haxul/Development/workspaces/c/linux_programming/data.txt";

int nonblock() {

    struct timeval tv;
    fd_set readfds;
    int ret;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);
    if (ret == -1) {
        perror("select");
        return 1;
    }

    if (!ret) {
        printf("%d seconds elapsed.", TIMEOUT);
        return 0;
    }


    if (FD_ISSET(STDIN_FILENO, &readfds)) {
        char buf[BUF_LEN];
        int len;

        len = read(STDIN_FILENO, buf, BUF_LEN);
        if (len == -1) {
            perror("read");
            return 1;
        }

        if (len) {
            buf[len] = '\0';
            printf("read %s", buf);
        }

        return 0;
    }

    perror("some gets wrong");
    return 1;

}

void check_opened_file() {

    int fd = open(url, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd == -1) {
        printf("errror");
        return;
    }

    printf("%d\n", fd);

    printf("create %s", url);

    close(fd);
}

void read_file() {
    ssize_t nr;
    char buffer[50];
    int fd = open(url, O_RDONLY);
    unsigned int len = 3;
    while ((nr = read(fd, &buffer, len)) != 0) {
        if (nr == -1) {
            printf("error +");
            return;
        }

        len -= nr;
    }

    printf("%s\n", buffer);

    printf("done");
}

void write_file() {
    const char *buf = "\nhello friend";
    ssize_t nr;
    int fd = open(url, O_WRONLY | O_APPEND);
    nr = write(fd, buf, strlen(buf));
    if (nr == -1) {
        printf("error");
    }
}