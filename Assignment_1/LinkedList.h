/*
CH-231-A
a1_p3.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
    private:
    public:
        T data;
        Node* next;
        Node* prev;
        // Type Node* because pointer to same class
        Node(T data);
        //Node(const Node& node_copy);
        ~Node();
        string toString();

};

template <class T> 
class List {
    private:
        T* front;
        T* end;
        int list_size;

    public:
        List();
        List(const List<Node<T>>& list_copy);
        List(int size, T* new_node);
        ~List();
        T* getFront();
        T* getEnd();
        T* popFront();
        T* popEnd();
        void pushFront(T* new_node);
        void pushEnd(T* new_node);
        int getNumEntries();

};