#include <cstring>
#include <cstdlib>
#include <cctype>
#include <memory>
#include <functional>

#include <vector>
#include <queue>
#include <unordered_map>

#include <mutex>
#include <thread>
#include <condition_variable>

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