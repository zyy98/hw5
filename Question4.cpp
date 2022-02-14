//
// Created by 张元一 on 12/02/2022.
//
#include <iostream>
#include <tuple>
int f(double d) { return static_cast<int>(2 * d); }

template <typename T>
class Counter{
public:
    Counter(T){
        count = 0;
    }
    template<typename... Args>
    void operator()(Args &&... args) {
        count ++;
    }

    int count;
};


Counter cf(f);

int main() {
    cf(1.3);
    cf(2.4);
    //std::cout << format("f was called {} times\n", cf.count);
    std::cout << cf.count;
}