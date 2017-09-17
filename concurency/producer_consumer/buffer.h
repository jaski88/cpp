#ifndef BUFFER_H
#define BUFFER_H

#include <future>
#include <thread>

class Buffer {
public:
    explicit Buffer(int size);
    ~Buffer();
    void add(int data);
    int get();
    void dump();

private:
    bool is_empty();
    bool is_full();

    int* m_data;
    int m_size;
    int m_count;
    int front;
    int end;

    std::condition_variable m_empty_cv;
    std::condition_variable m_full_cv;
    std::mutex m_mutex;
};

#endif // BUFFER_H
