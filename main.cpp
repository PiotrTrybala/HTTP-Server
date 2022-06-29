#include <iostream>
#include "web_server.h"

int main() {
    std::cout << "Hello World!" << std::endl;
    Server server(8010);
    if (!server.start_server()) {
        return -1;
    }
    server.server_accept();
    if (!server.stop_server()) {
        return -1;
    }
    return 0;
}