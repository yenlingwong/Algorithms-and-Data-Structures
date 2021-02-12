/*
CH-231-A
a1_p2.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
using namespace std;

template<typename T>
class Stack {
    private:
        T *stack_arr;
        int stack_size;
        T stack_top;
        int NumEntries;

    public:
        Stack();
        Stack(const Stack&);
        Stack(int size);
        ~Stack();

        bool push(T element);
        void extend();
        bool pop(T& out);
        T back(void);
        int getNumEntries();

};