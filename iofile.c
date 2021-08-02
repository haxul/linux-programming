
#include <fcntl.h>
#include "iofile.h"


void check_opened_file() {

    int fd = open("/home/haxul/Development/workspaces/c/linux_programming/data.txt", O_RDONLY);
    if (fd == -1) {
        printf("errror");
        return;
    }

    printf("%d\n", fd);

    printf("done");
}