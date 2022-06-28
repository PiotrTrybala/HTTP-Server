#include "server.hpp"

void Server::init(short port)
{

    int opt = 1;

    data = (struct http_server *)malloc(sizeof(struct http_server));
    data->server_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in *addr = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
    addr->sin_family = AF_INET;
    addr->sin_addr.s_addr = INADDR_ANY;
    addr->sin_port = htons(port);

    data->addr = addr;

    if (setsockopt(data->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        free(data);
        exit(0);
    }

    int size = sizeof(struct sockaddr_in);

    if (bind(data->server_fd, (struct sockaddr *)data->addr, (socklen_t)size) < 0)
    {
        perror("bind");
        free(data);

        exit(0);
    }
}

Server::Server()
{
    init(DPORT);
}
Server::Server(short port)
{
    init(port);
}
Server::~Server()
{
    free(this->data);
}

bool Server::start_server()
{
}

bool Server::accept()
{
}

bool Server::stop_server()
{
}