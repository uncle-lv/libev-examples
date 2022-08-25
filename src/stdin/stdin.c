#include <stdio.h>
#include <ev.h>
#include <unistd.h>

#define BUF_SIZE 512

static void stdin_cb(struct ev_loop *loop, ev_io *watcher, int revents) {
    puts("--- READABLE EVENT ---");
    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);
    read(watcher->fd, buf, BUF_SIZE);
    printf("user's input: %s\n", buf);
    printf("please input: \n");
}

int main(void) {
    struct ev_loop *loop = EV_DEFAULT;
    ev_io stdin_watcher;

    ev_io_init(&stdin_watcher, stdin_cb, 0, EV_READ);
    ev_io_start(loop, &stdin_watcher);
    printf("please input: \n");
    ev_run(loop, 0);
    return 0;
}