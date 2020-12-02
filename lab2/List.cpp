#include <cstdint>
#include "List.h"

template <class T, std::size_t Size = 0>
List::List() : count(0), capacity(Size) {
    head = new Node<T>();
    tail = new Node<T>();
}

template <class T>
void List::push_back(const T &e) {
    if (count == capacity) exit(1);
    if (isEmpty()) {
        auto *newNode = new Node<T>(e);
        head->_next = newNode;
        tail->_prev = newNode;
    } else {
        auto Last = tail->_prev;
        auto *newNode = new Node<T>(e, nullptr, Last);
        Last->_next = newNode;
        tail->_prev = newNode;
    }
    count++;
}

template <class T>
void List::clear() {
    while (tail->_prev!=nullptr) {
        Node<T> *remove = tail->_prev;
        tail->_prev = remove->_prev;
        delete remove;
    }
    count = 0;
}

template <class T>
void List::operator[] (int index) const {
    Node<T>* tmp = head->_next;
    while(index--)
        tmp = tmp->_next;

    return tmp->_value;
}