#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

int main() {
    char foo[47], bar[50], baz[48];
    struct iovec iov[3];
    ssize_t nr;
    int fd, i;

    fd = open("buccaneer.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    /* set up out iovec structures */
    iov[0].iov_base = foo;
    iov[0].iov_len = sizeof (foo);
    iov[1].iov_base = bar;
    iov[1].iov_len = sizeof(bar);
    iov[2].iov_base = baz;
    iov[3].iov_len = sizeof(baz);

    /* read into the structures with a single call */
    nr = readv(fd, iov, 3);
    if (nr == -1) {
        perror("readv")
        return 1;
    }
    return 0;
}