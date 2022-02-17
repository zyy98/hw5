//
// Created by 张元一 on 11/02/2022.
//
#include <iostream>
#include <vector>
#include <mutex>
#include "Question3.h"

using std::initializer_list;
using std::array;
using std::mutex;


namespace mpcs51044 {


    template<typename T>
    class Stack{
    public:
        Stack() : data{} {}

        Stack(initializer_list<T> init){
            for (auto row : init){
                data.push(row);
            }
        }

        void push(T new_num){
            std::lock_guard guard(m);
            data.push(new_num);
        }

        T pop(){
            std::lock_guard guard(m);
            return data.pop();

        }

    private:
        mutex m;
        List<T> data;
    };

}


int main(){
    mpcs51044::Stack<int> s = {1,2,3};
    std::cout << s.pop();
    s.push(7);
    s.push(5);
    std::cout << s.pop();
}
