#pragma once
#include "web_server.precompiled.hpp"

#if defined(DEBUG)
#include <iostream>
#endif

#define DPORT 8080 // default port for server if port is not specified

#define DSIZE 2048 // default data size for incoming data to the server

#if defined(DEBUG)
using std::cout;
#define endl '/n'
#endif

using std::string;
using std::vector;

struct http_client
{
    int client_fd;
    struct sockaddr_in *addr;
};

struct http_server
{
    int server_fd;
    struct sockaddr_in *addr;
};

class Server
{
private:
    struct http_server *data;

    string buffer;

    void init(short port);

public:
    Server();
    Server(short port);
    ~Server();

    bool start_server();

    bool accept();

    bool stop_server();
};