#include "thqueue.hpp"

template<class T>
void ThQueue<T>::enqueue(T t)
{
    lock_guard<mutex> lock(m);
    q.push(t);
    c.notify_one();
}
template<class T>
T ThQueue<T>::dequeue()
{
    unique_lock<mutex> lock(m);
    while(q.empty()) {
        c.wait(lock);
    }
    T val = q.front();
    q.pop();
    return val;
}