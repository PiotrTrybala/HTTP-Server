#pragma once
#include "web_server.precompiled.hpp"

#define DEBUG

#define DPORT 8080 // default port for server if port is not specified

#define DSIZE 512 // default data size for incoming data to the server

#define LSIZE 10 // default size for listen() function

#if defined(DEBUG)
#include <iostream>
using std::cout;
using std::endl;
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
    void init(short port);
    string read_socket(int sock);
public:
    Server();
    Server(short port);
    ~Server();

    bool start_server();

    bool server_accept();

    bool stop_server();
};