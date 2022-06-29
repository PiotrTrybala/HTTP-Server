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
    shutdown(data->server_fd, SHUT_RDWR);
    close(data->server_fd);
    free(this->data);
}

bool Server::start_server()
{
    if (listen(data->server_fd, LSIZE) != 0) {
        return false;
    }
    return true;
}

bool Server::server_accept()
{
    int client_fd = -1;
    int s = sizeof(struct sockaddr_in);
    struct sockaddr_in* addr = (struct sockaddr_in*) malloc(sizeof(struct sockaddr_in));
    while((client_fd = accept(data->server_fd, (struct sockaddr*) addr, (socklen_t*) &s)) > 0) {
        string buf = read_socket(client_fd);

        cout << "Buffer: " << buf << endl;

    }
    return true;
}

string Server::read_socket(int sock) {
    string buf;
    char tbuf[DSIZE];
    memset(tbuf, 0, DSIZE);
    ssize_t read_size = 0;

    while((read_size = read(sock, tbuf, DSIZE)) > 0) {
        #if defined(DEBUG)
            printf("[INFO] Received %ld bytes.\n", read_size);
        #endif

        printf("tbuf %ld: %s\n", read_size, tbuf);

        buf += tbuf;
    }
    return buf;
}

bool Server::stop_server()
{
    shutdown(data->server_fd, SHUT_RDWR);
    close(data->server_fd);
    free(this->data);
    exit(-189);
}