#include "buffer.h"

#include <iostream>
#include <sstream>

namespace {
const std::chrono::milliseconds TIMEOUT(1000);
}

Buffer::Buffer(int size)
    : m_size(size)
    , m_count(0)
    , front(0)
    , end(0)
{
    m_data = new int[size];
}

Buffer::~Buffer()
{
    delete[] m_data;
}

void Buffer::add(int data)
{
    std::unique_lock<std::mutex> lock(m_mutex);

    bool result = m_full_cv.wait_for(lock, TIMEOUT, [this]() {
        return !is_full();
    });

    if (result) {
        m_data[end] = data;
        end++;
        end = end % m_size;
        m_count++;

        dump();

        m_empty_cv.notify_all(); // notify threads that want to consume data
    } else {
        std::cout << "timeout during adding: " << data;
    }
}

int Buffer::get()
{
    int data = -1;
    std::unique_lock<std::mutex> lock(m_mutex);

    bool result = m_empty_cv.wait_for(lock, TIMEOUT, [this]() {
        return !is_empty();
    });

    if (result) {
        data = m_data[front];
        m_data[front] = 0;
        front++;
        front = front % m_size;
        --m_count;

        dump();
        m_full_cv.notify_all(); // notify threads that want to produce data
    } else {
        std::cout << "timeout during getting: " << data << std::endl;
    }

    return data;
}

void Buffer::dump()
{
    std::stringstream ss;

    ss << "| ";

    for (int i = 0; i < m_size; i++) {
        ss << m_data[i] << " | ";
    }

    std::cout << ss.str() << std::endl;
}

bool Buffer::is_empty()
{
    return m_count == 0;
}

bool Buffer::is_full()
{
    return m_count == m_size;
}
