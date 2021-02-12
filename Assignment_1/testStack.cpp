/*
CH-231-A
a1_p2.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
Stack<T>::Stack() {
    this->stack_size = 10;
    this->stack_arr = new T[this->stack_size];
    this->stack_top = -1;
    this->NumEntries = 0;
    cout << "A Default Stack of size " << this->stack_size << " has been created" << endl;
}

template <class T>
Stack<T>::Stack(const Stack& s) {
    this->stack_size = s.stack_size;
    this->stack_arr = s.stack_arr;
    this->stack_top = s.stack_top;
    this->NumEntries = s.NumEntries;
    cout << "A Copy of a Stack has been created" << endl;
}

template <class T>
Stack<T>::Stack(int size) {
    this->stack_size = size;
    this->stack_arr = new T[this->stack_size];
    this->stack_top = -1;
    this->NumEntries = 0; 
    cout << "A Stack of size " << this->stack_size  << " has been created" << endl;
}

template <class T>
void Stack<T>::extend() {
    T *extended_array = new T[(this->stack_size)*2];
    for (int i = 0; i < this->stack_size; i++) 
        extended_array[i] = this->stack_arr[i];
    delete[] stack_arr;
    this->stack_size *= 2;
    this->stack_arr = extended_array;
}

template <class T>
bool Stack<T>::push(T element) {
    if (getNumEntries() < this->stack_size) {
        this->stack_arr[(int)(++(this->stack_top))] = element;
        this->NumEntries++;
        return 1;
    } else {
        return 0;
    }
    
}

template <class T>
bool Stack<T>::pop(T &out) {
    if (getNumEntries() != 0) {
        this->stack_top--;
        this->NumEntries--;
        cout << out << " has been popped from the stack" << endl;
        return 1;
    } else {
        return 0;
    }
}

template <class T>
T Stack<T>::back(void) {
    return this->stack_top;
}

template <class T>
int Stack<T>::getNumEntries() {
    cout << "The number of elements is " << this->NumEntries << endl;
    return this->NumEntries;
}

template <class T>
Stack<T>::~Stack() {
    delete[] stack_arr;
    cout << "The Stack has been cleared" << endl;
}

int main() {
    Stack<int> A;

    for (int i = 0; i < 15 ; i++) {
        if (A.push(i)) {
            cout << i << " has been pushed into the stack. " << endl;
        } else {
            cout << "Stack Overflow" << endl;
            break;
        }
    }

    Stack<int> B(A);
    for (int i = 0; i < 10 ; i++) {
        if (B.push(i*i)) {
            cout << i*i << " has been pushed into the stack. " << endl;
        } else {
            B.extend();
        }
    }

    for (int i = 0; i < 30; i++) {
        int popped_val = B.back();
        if (B.pop(popped_val)) {
            // So be it
        } else {
            cout << "Stack Underflow." << endl;
            break;
        }
    }

    if (B.getNumEntries() > 0) {
        cout << "Your last element is " << B.back() << endl;
    } else {
        cout << "There are no more elements left." << endl;
    }

    Stack<char> C(5);
    unsigned char c = 'A';
    for (int i = 0; i < 5; i++) {
        if (C.push(c)) {
            cout << c << " has been pushed into the stack." << endl;
        }
        c++;
    }
    
    return 0;
}