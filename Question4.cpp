//
// Created by 张元一 on 12/02/2022.
//
#include <iostream>
#include <tuple>
int f(double d) { return static_cast<int>(2 * d); }

template <typename T>
class Counter{
public:
    Counter(T func, bool counted = true){
        count = 0;
        cur_func = func;
        isCounted = counted;
    }
    template<typename... Args>
    auto operator()(Args &&... args) {
        if(isCounted){
            count ++;
        }
        return cur_func(std::forward<Args>(args)...);
    }

    int count;
private:
    bool isCounted;
    T cur_func;
};


Counter cf(f); //can also be used as cf(f, false)

int main() {
    cf(1.3);
    cf(2.4);
    //std::cout << format("f was called {} times\n", cf.count);
    std::cout << cf.count;
}