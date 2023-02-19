#pragma once
#include <queue>
#include <thread>
#include <mutex>              // pthread_mutex_t
#include <condition_variable> // pthread_condition_t

// 异步写日志的日志队列
template <typename T>
class LockQueue
{
public:
    void Push(const T &data);
    T &Pop();

private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_condvariable;
};