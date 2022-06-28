#include <cstring>
#include <cstdlib>
#include <cctype>
#include <memory>
#include <functional>

#include <vector>
#include <unordered_map>

#define LINUX

#if defined(LINUX)
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#elif defined(WINDOWS)
#error "Windows is not supported yet!"
#endif