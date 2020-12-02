#ifndef CLION_LIST_H
#define CLION_LIST_H

template <class T>
class Node {
public:
    explicit Node(const T &e = T(), Node *n = nullptr, Node *p = nullptr) : _value(e), _next(n), _prev(p) {}
    ~Node() = default;
    T _value;
    Node *_next;
    Node *_prev;

};

template <class T, size_t Size = 0>
class List {

    Node<T> *head;
    Node<T> *tail;

    std::size_t count;
    std::size_t capacity;

public:
    List() : count(0), capacity(Size) {
        head = new Node<T>();
        tail = new Node<T>();
    }

    bool isEmpty() { return (head->_next == nullptr); }

    void push_back(const T &e) {
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
    void clear() {
        while (tail->_prev!=nullptr) {
            Node<T> *remove = tail->_prev;
            tail->_prev = remove->_prev;
            delete remove;
        }
        count = 0;
    }
    ~List() {
        clear();
        delete head;
        delete tail;
    }

    void operator += (const T & item) {
        push_back(item);
    }

    size_t size () const { return count; }

    const T& operator [] (int index) const {
        Node<T>* tmp = head->_next;
        while(index--)
            tmp = tmp->_next;

        return tmp->_value;
    }
};

#endif