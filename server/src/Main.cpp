#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/ioctl.h>

#include "Args.hpp"
#include "ArcadeServer.hpp"

int main(int argc, char** argv)
{
    Args args = parse_args(argc, argv);

    printf("ArcadeTUI Server listening\n");
    
    int sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Failed to open server socket\n");
        return 1;
    }

    struct sockaddr_un saddr = { AF_UNIX, "arcadetui.sock" };
    bind(sock, (struct sockaddr*)&saddr, sizeof(saddr));

    listen(sock, 10);
    
    char message[] = "Hello, goodbye\n";
    int client;
    for(;;) {
        client = accept(sock, NULL, NULL);
        printf("Connection established\n");

        send(client, message, sizeof(message), 0);

        close(client);
    }
   
    shutdown(sock, SHUT_RDWR);
    close(sock);

    return 0;
}
