
#include <fcntl.h>
#include <unistd.h>
#include "iofile.h"

char *url = "/home/haxul/Development/workspaces/c/linux_programming/data.txt";

void check_opened_file() {

    int fd = open(url, O_WRONLY | O_CREAT | O_TRUNC , 0664);
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

}