/*
CH-231-A
a9_p1b.h
Yen Ling Wong
ywong@jacobs-university.de
Queue Implementation with 2 Stacks Header File
*/

#include <iostream>

template <class T>
struct StackNode {
    T data;
    StackNode* next;
};

template <typename T>
class Stack {
    private:
        int current_size;

    public:
        Stack();
        Stack(int new_size);
        void push(T x);
        T pop();
        bool isEmpty();
        StackNode<T>* top;
};

template <typename T>
class Queue {
    private:
        Stack<T>* inbox_stack;
        Stack<T>* outbox_stack;
        int queue_size;
    public:
        Queue();
        void enqueue(T x);
        T dequeue();
        bool is_queue_empty();
};