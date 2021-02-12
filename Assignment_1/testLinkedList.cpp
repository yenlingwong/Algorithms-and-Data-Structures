/*
CH-231-A
a1_p3.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
#include <string>
#include <sstream>

#include "LinkedList.h"

using namespace std;

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    cout << "A Node has been created." << endl;
}

template <class T>
Node<T>::~Node() {
    //
}

template <class T>
string Node<T>::toString() {
    stringstream s;
    s << this->data;
    return s.str();
}
// Using stringstream to convert value to String

template <class T>
List<T>::List() {
    this->front = NULL;
    this->end = NULL;
    this->list_size = 0;

    cout << "A list has been created." << endl;
}
// Default Constructor

template <class T>
List<T>::List(const List<Node<T>>& list_copy) {
    if (list_copy.front == NULL) {
        this->front = NULL;
        this->end = NULL;
        this->list_size = 0;
    } else {
        this->list_size = 0;
        T* temp = list_copy.end;
        while(temp->prev != NULL) {
            this->pushFront(new Node<T>(temp->data));
            temp = temp->prev;
            this->list_size++;
        }
        delete[] temp;       
    }
}
// Copy Constructor for List

template <class T>
List<T>::List(int size, T* new_node) {
    cout << "A list has been created" << endl;
    this->front = NULL;
    this->end = NULL;
    this->list_size = 0;

    this->pushFront(new_node);
    
    for (int i = 0; i < size; i++) {
        this->pushFront(new Node<int>(i*i));
    }
    // Must manually change type every single time
    // Since compiler doesn't allow an arbitrary type T
}
// Parametric Constructor


template <class T>
List<T>::~List() {
    while (this->front != NULL) {
        T* temp = this->front;
        this->front = this->front->next;
        delete[] temp;
    }
    
    cout << "A list has been cleared." << endl;
}
// Destructor

template <class T>
T* List<T>::getFront() {
    return this->front;
}
// Returning head element without removing

template <class T>
T* List<T>::getEnd() {
    return this->end;
}
// Returning tail element without removing

template <class T>
void List<T>::pushFront(T* new_node) {
    new_node->next = NULL;
    new_node->prev = NULL;

    if (this->front == NULL) {
        this->front = new_node;
        this->end = this->front;
        this->list_size++;
        cout << this->getFront()->toString() << " has been pushed to the front." << endl;
    } else {
        this->front->prev = new_node;
        new_node->next = this->front;
        this->front = new_node;
        this->list_size++;
        cout << this->getFront()->toString() << " has been pushed to the front." << endl;
        
    }
}
// Method to add element to the front of the list

template <class T>
void List<T>::pushEnd(T* new_node) {
    new_node->next = NULL;
    new_node->prev = NULL;

    if (this->front == NULL) {
        this->front = new_node;
        this->end = this->front;
        this->list_size++;
        cout << this->getEnd()->toString() << " has been pushed to the end." << endl;
    } else {
        this->end->next = new_node;
        new_node->prev = this->end;
        this->end = new_node;
        this->list_size++;
        cout << this->getEnd()->toString() << " has been pushed to the end." << endl;
    }
}
// Method to add element to the back of the list

template <class T>
T* List<T>::popFront() {
    T* temp = this->front;
    if (this->front == NULL) {
        cout << "The List is Empty." << endl;
    } else {
        this->front = this->front->next;
        this->list_size--;
    }
    return temp;
}
// Method to return head element and removing it

template <class T>
T* List<T>::popEnd() {
    T* temp = this->end;
    if (this->front == NULL) {
        cout << "This List is Empty" << endl;
    } else {
        this->end = this->end->prev;
        this->list_size--;
    }
    return temp;
}
// Method to return head element and removing it

template <class T>
int List<T>::getNumEntries() {
    return list_size;
}
// Method to return number of elements in a list

int main() {
    List<Node<int>> A;
    // Default Constructor

    A.popFront();
    // shows List is empty and nothing is popped
    cout << "There are " << A.getNumEntries() << " elements in the list A." << endl;
    cout << endl;

    for (int i = 0; i < 5; i++) {
        A.pushFront(new Node<int>(i));
        cout << "There are " << A.getNumEntries() << " elements in the list A." << endl;
    }
    cout << endl;

    List<Node<int>> B(A);
    // Copy Constructor
    cout << "Number of entries in B: " << B.getNumEntries() << endl;
    cout << endl;

    for (int i = 0; i < 2; i++) {
        cout << A.popFront()->toString() << " has been removed from the front in A." << endl;
    }
    for (int i = 0; i < 2; i++) {
        cout << A.popEnd()->toString() << " has been removed from the back in A." << endl;
    }
    cout << endl;
    cout << "Number of entries in A: " << A.getNumEntries() <<  endl;
    cout << "Number of entries in B: " << B.getNumEntries() <<  endl;
    cout << "The first value of A is: " << A.getFront() ->toString() << endl;
    cout << "The first value of B is: " << B.getFront() ->toString() << endl;
    cout << endl;

    List<Node<char>> C;
    for (char c = 'A'; c < 'H'; c++) {
        C.pushEnd(new Node<char>(c));
        cout << "There are " << C.getNumEntries() << " elements in the list C." << endl;
    }
    cout << endl;
    cout << "The first element in C is " << C.getFront()->toString() << endl;
    cout << "The last element in C is " << C.getEnd()->toString() << endl;
    cout << endl;
   
    List<Node<int>> D(5, new Node<int>(23));
    // Parametric Constructor
    // If change type here, must change in the constructor above
    cout << "Number of Entries in D: " << D.getNumEntries() << endl;
    cout << "The first element in D is " << D.getFront()->toString() << endl;
    cout << "The last element in D is " << D.getEnd()->toString() << endl;
    cout << endl;
    
    return 0;
}