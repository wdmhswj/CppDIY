#include "ThreadPool/safe_queue.h"
#include <thread>
#include <iostream>
#include <vector>

SafeQueue<int> g_sq;

void func() {
    int count = 0;
    std::cout << "func begin" << std::endl;
    for(int i=0; i<10000000; ++i) {
        g_sq.enqueue(i);
    }
    for(int i=0; i<10000000; ++i) {
        int tmp = 0;
        if(!g_sq.dequeue(tmp)) {
            std::cout << "dequeue error: empty now" << std::endl;
        }
        if(tmp%1000000==0)
            std::cout << tmp << std::endl;
    }
    std::cout << "func end" << std::endl;
}
int main() {
    std::vector<std::thread> thrs;
    for(int i=0; i<5; ++i) {
        thrs.emplace_back(&func);
    }
    for(int i=0; i<thrs.size(); ++i) {
        thrs[i].join();
    }

    return 0;
}