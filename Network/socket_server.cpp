// server.cpp
#include <iostream>
#include <vector>
#include <unistd.h>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/event.h>
#include <fcntl.h>

constexpr int PORT = 8888;
constexpr int MAX_EVENTS = 64;

int make_socket_non_blocking(int sfd) {
    int flags = fcntl(sfd, F_GETFL, 0);
    return fcntl(sfd, F_SETFL, flags | O_NONBLOCK);
}

int socket_server_main()
{
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (listen_fd < 0)
    {
        perror("socket");
        return 1;
    }

    int opt = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in server_addr {};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(listen_fd, SOMAXCONN) < 0) {
        perror("listen");
        return 1;
    }

    make_socket_non_blocking(listen_fd);

    int kq = kqueue();
    if (kq == -1)
    {
        perror("kqueue");
        return 1;
    }

    struct kevent change;
    
    EV_SET(&change, listen_fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
    if (kevent(kq, &change, 1, NULL, 0, NULL) == -1)
    {
        perror("kevent register listen_fd");
        return 1;
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    std::vector<struct kevent> events(MAX_EVENTS);

    while (true)
    {
        int nev = kevent(kq, NULL, 0, events.data(), MAX_EVENTS, NULL);
        if (nev == -1) {
            perror("kevent");
            break;
        }

        for (int i = 0; i < nev; ++i) {
            int fd = events[i].ident;

            if (fd == listen_fd) {
                // Accept new client
                sockaddr_in client_addr {};
                socklen_t client_len = sizeof(client_addr);
                int client_fd = accept(listen_fd, (sockaddr*)&client_addr, &client_len);
                if (client_fd < 0) {
                    perror("accept");
                    continue;
                }

                make_socket_non_blocking(client_fd);
                EV_SET(&change, client_fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
                kevent(kq, &change, 1, NULL, 0, NULL);
                std::cout << "Accepted new client: fd " << client_fd << std::endl;
            } else if (events[i].filter == EVFILT_READ) {
                char buffer[1024];
                ssize_t n = read(fd, buffer, sizeof(buffer));
                if (n <= 0) {
                    std::cout << "Client disconnected: fd " << fd << std::endl;
                    close(fd);
                } else {
                    buffer[n] = '\0';
                    std::cout << "Received from client " << fd << ": " << buffer << std::endl;
                }
            }
        }
    }

    close(listen_fd);
    return 0;
}

