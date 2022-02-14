#include <iostream>
#include <thread>
#include "../jthread-master/source/jthread.hpp"

void hello_threads() {
    std::cout << "Hello Concurrent World\n";
}

int
main() {
    // Print in a different thread
    //std::jthread t;
    std::jthread t(hello_threads);
    //t.join(); // Wait for that thread to complete
}
