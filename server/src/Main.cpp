#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <thread>
#include <iostream>

#include "Args.hpp"
#include "ArcadeServer.hpp"

bool g_running = true;

void listen_thread()
{
    int sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Failed to open server socket\n");
        return;
    }

    struct sockaddr_un saddr = { AF_UNIX, "arcadetui.sock" };
    bind(sock, (struct sockaddr*)&saddr, sizeof(saddr));

    listen(sock, 10);

    char message[] = "Hello, goodbye\n";
    int client;
    while (g_running) {
        client = accept(sock, NULL, NULL);
        printf("Connection established\n");

        send(client, message, sizeof(message), 0);

        close(client);
    }

    shutdown(sock, SHUT_RDWR);
    close(sock);
}

int main(int argc, char** argv)
{
    Args args = parse_args(argc, argv);

    printf("ArcadeTUI Server listening\n");
    
    std::thread t(listen_thread);
    t.detach();
    
    string line;
    
    g_running = true;
    printf("> ");    
    while (getline(std::cin, line)) {
        if (line == "exit") {
            g_running = false;
            break;
        }

        printf("> ");
    }
    
    t.join();

    return 0;
}
