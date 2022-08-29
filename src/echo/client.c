#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 80
#define PORT 5000

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr;
    char buf[MAXLINE];
    bzero(buf, sizeof(buf));

    if (argc != 2) {
        fputs("usage: ./client {msg}\n", stderr);
        exit(1);
    }

    char *msg = argv[1];
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    server_addr.sin_port = htons(PORT);
    connect(client_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    write(client_fd, msg, MAXLINE);

    int n = read(client_fd, buf, MAXLINE);
    if (n > 0) {
        printf("response from server: %s\n", buf);
    } else {
        close(client_fd);
    }
    return 0;
}