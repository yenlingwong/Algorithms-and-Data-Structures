/*
CH-231-A
a9_p1a.h
Yen Ling Wong
ywong@jacobs-university.de
Stack with Linked List Header File
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
        int size;
        int current_size;

    public:
        Stack();
        Stack(int new_size);
        void push(T x);
        T pop();
        bool isEmpty();
        StackNode<T>* top;
};