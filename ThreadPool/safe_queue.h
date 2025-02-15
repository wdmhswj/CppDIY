#pragma once

#include <queue>
#include <mutex>

template<typename T>
class SafeQueue {
private:
    std::queue<T> m_queue;
    mutable std::mutex m_mutex;
public:
    SafeQueue() {}
    SafeQueue(const SafeQueue& o) = delete;
    SafeQueue(SafeQueue&& o) = delete;
    ~SafeQueue() {}

    bool empty() const {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }

    size_t size() const {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.size();
    }

    // 队列添加元素
    void enqueue(const T& t) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.emplace(t);
    }

    // 队列取出元素
    bool dequeue(T& t) {
        std::unique_lock<std::mutex> lock(m_mutex);
        if(m_queue.empty())
            return false;
        t = std::move(m_queue.front());
        m_queue.pop();
        return true;
    }
};