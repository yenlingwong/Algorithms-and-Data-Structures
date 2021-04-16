/*
CH-231-A
a1_p3.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
#include "a1_p3.h"

using namespace std;

template <typename T>
List<T>::List() {
    this->front = NULL;
    this->end = NULL;
    this->list_size = 0;

    std::cout << "A List has been created." << std::endl;
}
// Default Constructor

template <typename T>
List<T>::List(const List<T>& list_copy) {
    if (list_copy.front == NULL) {
        this->front = NULL;
        this->end = NULL;
        this->list_size = 0;
    } else {
        this->list_size = 0;
        this->front = NULL;
        this->end = NULL;
        struct Node<T>* current = list_copy.front;
        while (current != NULL) {
            this->pushFront(current->data);
            current = current->next;
        }
        std::cout << "A List has been copied." << std::endl;
    }
}
// Copy Constructor

template <typename T>
List<T>::~List() {
    while (this->list_size!= 0) {
        this->popEnd();
    }
    std::cout << "The List has been cleared." << std::endl;
}
// Destructor


template <typename T>
T List<T>::getFront() {
    return this->front->data;
}
// Returning data of head element without removing

template <typename T>
T List<T>::getEnd() {
    return this->end->data;
}
// Returning data of tail element without removing

template <typename T>
void List<T>::pushFront(T info) {
    Node<T>* new_node = new struct Node<T>;
    new_node->data = info;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (this->front == NULL) {
        this->front = new_node;
        this->end = new_node;
        this->list_size++;
        std::cout << this->getFront() << " has been pushed to the front." << std::endl;
    } else {
        this->front->prev = new_node;
        new_node->next = this->front;
        this->front = new_node;
        this->list_size++;
        std::cout << this->getFront() << " has been pushed to the front." << std::endl;
    }
}
// Method to add element to the front of the list

template <typename T>
void List<T>::pushEnd(T info) {
    Node<T>* new_node = new struct Node<T>;
    new_node->data = info;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (this->front == NULL) {
        this->front = new_node;
        this->end = new_node;
        this->list_size++;
        std::cout << this->getEnd() << " has been pushed to the end." << std::endl;
    } else {
        this->end->next = new_node;
        new_node->prev = this->end;
        this->end = new_node;
        this->list_size++;
        std::cout << this->getEnd() << " has been pushed to the end." << std::endl;
    }
}
// Method to add element to the back of the list

template <class T>
void List<T>::popEnd() {
    if (this->front == NULL) {
        std::cout << "The List is empty." << std::endl;
    } else {
        Node<T>* temp = this->end;
        this->end = this->end->prev;
        this->list_size--;
        std::cout << temp->data << " has been popped from the end." << std::endl;
        delete temp;
    }
}
// Method to remove the end of the list

template <class T>
void List<T>::popFront() {
    if (this->front == NULL) {
        std::cout << "The List is empty." << std::endl;
    } else {
        Node<T>* temp = this->front;
        this->front = this->front->next;
        this->list_size--;
        std::cout << temp->data << " has been popped from the front." << std::endl;
        delete temp;
    }
    if (this->front != NULL) {
        this->front->prev = NULL;
    }
}
// Method to remove head of the list

template <class T>
int List<T>::getNumEntries() {
    return this->list_size;
}

int main() {
    List<int> A;
    // Default Constructor

    A.popFront();
    // shows List is empty and nothing is popped
    cout << "There are " << A.getNumEntries() << " elements in the list A." << endl;
    cout << endl;

    for (int i = 0; i < 5; i++) {
        A.pushFront(i);
        cout << "There are " << A.getNumEntries() << " elements in the list A." << endl;
    }
    cout << endl;

    List<int> B(A);
    cout << "Number of entries in B: " << B.getNumEntries() << endl;
    cout << endl;

    List<char> C;
    for (char c = 'A'; c < 'Z'; c++) {
        C.pushFront(c);
    }
    cout << endl;
    cout << "Number of Entries in D: " << C.getNumEntries() << endl;
    cout << "The first element in D is " << C.getFront() << endl;
    cout << "The last element in D is " << C.getEnd() << endl;
    cout << endl;
    return 0;
}
// TA's Comment: delete[] temp works only for arrays not linked list. use delete -0.05, pop push should also deallocate memory -0.05 (fixed). Also create all constructors total: 1.9
