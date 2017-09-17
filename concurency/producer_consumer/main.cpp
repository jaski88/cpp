#include <iostream>
#include <vector>

#include "buffer.h"

using namespace std;

namespace {
const int BUFFER_SIZE = 5;
const int PRODUCERS_SIZE = 20;
const int CONSUMERS_SIZE = 10;
}

int main(int argc, char* argv[])
{
    Buffer buffer(5);

    std::vector<std::thread> threads;

    const auto consume = [&buffer](const int id) {
        std::cout << "consumer#" << id << " waiting..." << std::endl;
        int value = buffer.get();
        std::cout << "consumer#" << id << " consumed value: " << value << std::endl;
    };

    const auto produce = [&buffer](const int id) {
        std::cout << "producer#" << id << " waiting..." << std::endl;
        int value = std::rand() % 100;
        buffer.add(value);
        std::cout << "producer#" << id << " produced value: " << value << std::endl;
    };

    for (int i = 0; i < CONSUMERS_SIZE; i++) {
        threads.push_back(std::thread(consume, i));
    }

    for (int i = 0; i < PRODUCERS_SIZE; i++) {
        threads.push_back(std::thread(produce, i));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
