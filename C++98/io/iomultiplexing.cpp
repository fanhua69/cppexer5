//
//  iomultiplexing.cpp
//  testcpp3
//
//  Created by hua fan on 2025-01-11.
//
#include <iostream>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_EVENTS 10

int iomultiplexing_main()
{
    int server_fd, client_fd;
    struct sockaddr_in address{};
    int kq;
    struct kevent change_list[MAX_EVENTS], event_list[MAX_EVENTS];

    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket failed");
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return 1;
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        return 1;
    }

    std::cout << "Listening on port " << PORT << std::endl;

    // Create a kqueue
    kq = kqueue();
    if (kq == -1) {
        perror("kqueue failed");
        return 1;
    }

    // Register the server socket with kqueue
    EV_SET(&change_list[0], server_fd, EVFILT_READ, EV_ADD, 0, 0, nullptr);

    while (true) {
        // Wait for events
        int event_count = kevent(kq, change_list, 1, event_list, MAX_EVENTS, nullptr);
        if (event_count < 0) {
            perror("kevent failed");
            return 1;
        }

        for (int i = 0; i < event_count; ++i) {
            if (event_list[i].flags & EV_ERROR) {
                std::cerr << "Error on event" << std::endl;
                continue;
            }

            if (event_list[i].ident == server_fd) {
                // Accept new connections
                sockaddr_in client_address;
                socklen_t addr_len = sizeof(client_address);
                client_fd = accept(server_fd, (struct sockaddr*)&client_address, &addr_len);
                if (client_fd < 0) {
                    perror("Accept failed");
                    continue;
                }

                std::cout << "New connection accepted." << std::endl;

                // Add the new client socket to the kqueue
                EV_SET(&change_list[0], client_fd, EVFILT_READ, EV_ADD, 0, 0, nullptr);
                kevent(kq, change_list, 1, nullptr, 0, nullptr);
            } else {
                // Handle data from a client
                char buffer[1024] = {0};
                int valread = read(event_list[i].ident, buffer, sizeof(buffer));
                if (valread == 0) {
                    // Client disconnected
                    close(event_list[i].ident);
                    std::cout << "Client disconnected." << std::endl;
                } else {
                    std::cout << "Received: " << buffer << std::endl;
                }
            }
        }
    }

    close(server_fd);
    return 0;
}
