//
// Created by 张元一 on 11/02/2022.
//
#include <iostream>
#include <vector>

using std::initializer_list;
using std::array;
using std::mutex;


namespace mpcs51044 {

template<typename T>
class Stack{

public:
    Stack() : data{} {}

    Stack(initializer_list<T> init){
        data = {init};
    }

    void push(int new_num){
        std::lock_guard guard(m);
        data.push_back(new_num);
    }

    int pop(){
        std::lock_guard guard(m);
        int last = data.back();
        data.pop_back();
        return last;

    }

private:
    mutex m;
    std::vector<T> data;
};
}


int main(){
    mpcs51044::Stack<int> s = {1,2,3};
    std::cout << s.pop();
    s.push(7);
    s.push(5);
    std::cout << s.pop();
}
