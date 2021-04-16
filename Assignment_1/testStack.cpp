/*
CH-231-A
a1_p2.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
#include "Stack.h"

using namespace std;

template <class T, int initialsize>
Stack<T, initialsize>::Stack() {
    this->stack_size = initialsize;
    this->stack_arr = new T[this->stack_size];
    this->stack_top = -1;
    this->NumEntries = 0;
    cout << "A Default Stack of size " << this->stack_size << " has been created" << endl;
}

template <class T, int initialsize>
Stack<T, initialsize>::Stack(const Stack& s) {
    this->stack_size = s.stack_size;
    this->stack_arr = new T[s.stack_size];
    for (int i = 0; i < s.stack_size; i++) {
        this->stack_arr[i] = s.stack_arr[i];
    }
    this->stack_top = s.stack_top;
    this->NumEntries = s.NumEntries;
    cout << "A Copy of a Stack has been created" << endl;
}

template <class T, int initialsize>
Stack<T, initialsize>::Stack(int size) {
    this->stack_size = size;
    this->stack_arr = new T[this->stack_size];
    this->stack_top = -1;
    this->NumEntries = 0; 
    cout << "A Stack of size " << this->stack_size  << " has been created" << endl;
}

template <class T, int initialsize>
void Stack<T, initialsize>::extend() {
    T *extended_array = new T[(this->stack_size)*2];
    for (int i = 0; i < this->stack_size; i++) 
        extended_array[i] = this->stack_arr[i];
    delete[] stack_arr;
    this->stack_size *= 2;
    this->stack_arr = extended_array;
}

template <class T, int initialsize>
bool Stack<T, initialsize>::push(T element) {
    if (getNumEntries() < this->stack_size) {
        this->stack_arr[(int)(++(this->stack_top))] = element;
        this->NumEntries++;
        return 1;
    } else {
        return 0;
    }
}

template <class T, int initialsize>
bool Stack<T, initialsize>::pop(T &out) {
    if (getNumEntries() != 0) {
        this->stack_top--;
        this->NumEntries--;
        cout << out << " has been popped from the stack" << endl;
        return 1;
    } else {
        return 0;
    }
}

template <class T, int initialsize>
T Stack<T, initialsize>::back(void) {
    return this->stack_top;
}

template <class T, int initialsize>
int Stack<T, initialsize>::getNumEntries() {
    cout << "The number of elements is " << this->NumEntries << endl;
    return this->NumEntries;
}

template <class T, int initialsize>
Stack<T, initialsize>::~Stack() {
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
    Stack<float, 20> f;
    float u = 2.536f;
    for (int i = 0; i < 6; i++) {
        if (f.push(u)) {
            cout << u << " has been pushed into the stack." << endl;
        }
    }
    return 0;
}
// TA's Comments: p2: doesn’t work for custom data types -0.1, copy constructor not implemented properly causing pointer issues -0.1 during deallocation. (fixed) total: 1.8
