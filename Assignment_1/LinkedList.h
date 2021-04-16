/*
CH-231-A
a1_p3.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};

template <typename T> 
class List {
    private:
        struct Node<T>* front;
        struct Node<T>* end;
        int list_size;

    public:
        List();
        List(const List<T>& list_copy);
        ~List();
        T getFront();
        T getEnd();
        void popFront();
        void popEnd();
        void pushFront(T info);
        void pushEnd(T info);
        int getNumEntries();
};
