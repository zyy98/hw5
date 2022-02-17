//
// Created by 张元一 on 16/02/2022.
//

#ifndef HW5_QUESTION3_H
#define HW5_QUESTION3_H
#include <memory>
#include <iostream>
#include <utility>
#include <cstddef>

template <typename T>
struct Node {
    T data;
    std::unique_ptr<Node> next;

    Node(T data) : data{data}, next{nullptr} {}
};

template <typename T>
struct List {
    List() : head{nullptr} {};

    void push(T data) {
        auto temp{std::make_unique<Node<T>>(data)};
        if (head) {
            temp->next = std::move(head);
            head = std::move(temp);

        } else {
            head = std::move(temp);
        }
    }

    T pop() {
        if (head == nullptr) {
            return NULL;
        }

        std::unique_ptr<Node<T>> temp = std::move(head);
        head = std::move(temp->next);
        return temp->data;
    }

private:
    std::unique_ptr<Node<T>> head;
};
#endif //HW5_QUESTION3_H
