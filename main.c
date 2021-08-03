#include <stdio.h>
#include "iofile.h"
#include <sys/types.h>
#include <unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024

int main() {
    return nonblock();
}
