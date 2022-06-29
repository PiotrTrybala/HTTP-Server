#include "web_server.precompiled.hpp"

using std::mutex;
using std::queue;
using std::lock_guard;
using std::unique_lock;
using std::condition_variable;

template <class T>
class ThQueue {
    private:
        queue<T> q;
        mutable mutex m;
        condition_variable c;
    public:
        ThQueue()
            : q()
            , m()
            , c() 
        {}
        ~ThQueue() {}

        void enqueue(T t);
        T dequeue();
};