/*
CH-231-A
a2_p1.cpp
Yen Ling Wong
y.wong@jacobs-university.de
*/

#include <iostream>
#include <list>
#include <fstream>

using namespace std;


int main() {
    list<int> A, B;
    // 1. Create two lists (A and B).
    int number;
    while(1) {
        cout << "Please enter an integer. " << endl;
        cin >> number;
        if (number <= 0) {
            break;
        } else {
            A.push_back(number);
            // 3. Insert the positive integers into list A by adding to the end.
            B.push_front(number);
            // 4. Insert the same positive integers into list B by adding to the beginning.
        }
    }
    // 2. Read integers from the keyboard until the entered integer is negative or zero.

    list<int>::iterator i;
    for (auto i = A.begin(); i != A.end(); i++) {
        cout << *i << " ";
    }
    // 5. Print list A (separated by spaces) on the standard output and
    cout << endl;
    ofstream myfile ("listB.txt");
    if(myfile.is_open()) {
        for (auto x : B) {
            myfile << x << " ";
        }
    // print list B (separated by spaces) into a file called “listB.txt”.
        myfile.close();
    } else {
        cout << "Unable to open file!" << endl;
    }
    
    cout << endl;
   // 6. Print an empty line on the standard output

    A.splice(A.end(), A, A.begin());
    B.splice(B.end(), B, B.begin());
    // 7. Move the first element of the lists to the end (for both lists).

    // 8. Print list A, print list B on the standard output (both separated by comma) using an iterator
    i = A.begin();
    for (;i != prev(A.end()); i++) {
        cout << *i << ",";
    }
    cout << *i << endl;
    // Make sure that you do not print a comma after the last element.

    i = B.begin();
    for (;i != prev(B.end()); i++) {
        cout << *i << ",";
    }
    cout << *i << endl;
    cout << endl;
    // 9. Print an empty line on the standard output.

    A.sort();
    B.sort();
    A.merge(B);
    // 10. Merge list B into list A.

    // 11. Print the result of the merging as a sorted list on the standard output (separated by spaces).
    for (i = A.begin(); i != A.end(); i++) {
        cout << *i << " ";
    }
    
    return 0;
}
