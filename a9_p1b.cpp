/*
CH-231-A
a9_p1b.cpp
Yen Ling Wong
ywong@jacobs-university.de
Queue Implementation with 2 Stacks Functions Definition File
*/

#include <iostream>
#include "a9_p1b.h"

template <class T>
Stack<T>::Stack() {
    this->current_size = 0;
    this->top = NULL;
    std::cout << "A Default Stack has been created." << std::endl;
}

template <class T>
bool Stack<T>::isEmpty() {
    if (this->top == NULL) {
        return true;
    }
    return false;
}

template <class T>
void Stack<T>::push(T x) {
    StackNode<T>* new_node = new StackNode<T>;
    new_node->data = x;
    new_node->next = NULL;

    if (this->top == NULL) {
        this->top = new_node;
    } else {
        new_node->next = top;
        this-> top = new_node;
    }
    this->current_size++;
}

template <class T>
T Stack<T>::pop() {
    if (this->isEmpty()) {
        std::cout << "Stack Underflow!" << std::endl;
        return -1;
    } else {
        StackNode<T>* temp = NULL;
        temp = this-> top;
        if (top->next != NULL) {
            top = top->next;
        } else {
            top = NULL;
        }
        return temp->data;
    }
}

template <class T>
Queue<T>::Queue() {
    Stack<T>* stack1 = new Stack<T>;
    Stack<T>* stack2 = new Stack<T>;
    this-> queue_size = 0;
    this-> inbox_stack = stack1;
    this-> outbox_stack = stack2;
    std::cout << "A Queue has been created." << std::endl;
}

template <class T>
bool Queue<T>::is_queue_empty() {
    if (this->inbox_stack->isEmpty() && this->outbox_stack->isEmpty()) {
        return true;
    }
    return false;
}

template <class T>
void Queue<T>::enqueue(T x) {
    this->inbox_stack->push(x);
    std::cout << x << " has been enqueued." << std::endl;
    this->queue_size++;
}

template <class T>
T Queue<T>::dequeue() {
    if (this->outbox_stack->isEmpty()) {
        while(!this->inbox_stack->isEmpty()) {
            this->outbox_stack->push(this->inbox_stack->pop());
        }
    }
    return this->outbox_stack->pop();
}

int main() {
    Queue<char> Q;
    for (int i = 'A'; i < 'Z'; i++) {
        Q.enqueue(i);
    }
    for (int i = 0 ; i < 10; i++) {
        std::cout << Q.dequeue() << " has been dequeued." << std::endl;
    }
    return 0;
}