#include "lockqueue.h"

template <typename T>
void LockQueue<T>::Push(const T &data)
{
    m_mutex.lock();
    m_queue.push(data);
    m_mutex.unlock();
}

template <typename T>
T &LockQueue<T>::Pop()
{
}