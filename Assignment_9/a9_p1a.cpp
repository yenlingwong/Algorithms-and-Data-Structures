/*
CH-231-A
a9_p1a.cpp
Yen Ling Wong
ywong@jacobs-university.de
Stack with Linked List Function Definitions File
*/

#include <iostream>
#include <string>
#include "a9_p1a.h"

template <class T>
Stack<T>::Stack() {
    this->size = -1;
    this->top = NULL;
    std::cout << "A Default Stack has been created." << std::endl;
}

template <class T>
Stack<T>::Stack(int newsize) {
    this->current_size = 0;
    this->size = newsize;
    this->top = NULL;
    std::cout << "A Stack of fixed size " << newsize << " has been created." << std::endl;
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

    if (this->top == NULL){
        this->top = new_node;
        std::cout << x << " has been pushed into the stack." << std::endl;
    } else if (this->size != -1 && this->current_size < this->size) {
        new_node->next = top;
        this-> top = new_node;
        std::cout << x << " has been pushed into the stack." << std::endl;
    } else if (this->size == -1) {
        new_node->next = top;
        this-> top = new_node;
        std::cout << x << " has been pushed into the stack." << std::endl;
    } else if (this->current_size == this->size) {
        std::cout << "Stack Overflow!" << std::endl;
    }
    if (this->size != -1 && this->current_size < this->size) {
        this->current_size++;
        std::cout << "The Size of the Fixed Stack is now " << current_size << std::endl;
    }
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

int main() {
    std::cout << "Implementing a Default Stack" << std::endl;
    Stack<int> s1;
    for (int i = 0 ; i < 11; i++) {
        s1.push(i);
    }
    for (int i = 0; i < 12; i++) {
        if (!s1.isEmpty()) 
            std::cout << s1.pop() << " has been popped from the stack." << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Implementing a Stack of Fixed Size" << std::endl;

    Stack<char> s2(10);
    for (int i = 'A'; i < 'M'; i++) {
        s2.push(i);
    }
    std::cout << s2.pop() << " has been popped from the stack." << std::endl;
    std::cout << s2.pop() << " has been popped from the stack." << std::endl;
    std::cout << s2.pop() << " has been popped from the stack." << std::endl;
    std::cout << s2.pop() << " has been popped from the stack." << std::endl;
    std::cout << "The top of the stack is " << s2.top->data << std::endl;
    return 0;
}