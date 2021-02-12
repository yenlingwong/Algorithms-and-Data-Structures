/*
CH-231-A
a2_p2.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<float> A;
// 1. Create a deque A able to store float values.
    float digit;

    while(1) {
        cout << "Please enter a float number." << endl;
        cin >> digit;

        if (digit == 0) {
            break;
// 2. Read floats from the keyboard until the entered float value is 0.
        } else if (digit > 0) {
            A.push_back(digit);
        } else {
            A.push_front(digit);
        }
// 3. Insert the positive elements at the end of A and the negative elements at the beginning of A.
    }

    deque<float>::iterator it;
    for (it = A.begin(); it != A.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
// 4. Print the elements of A on the standard output separated by spaces.

    cout << endl;
// 5. Print an empty line on the standard output.

    for (it = A.begin(); it != A.end(); it++) {
        if (*it > (float)0) {
            A.insert(it, 0);
            break;
        }
    }
//6. Add the value 0 into the middle of the deque (between the last negative and before the first
// positive element).
    
    it = A.begin();
    for (; it != A.end() - 1; it++) {
        cout << *it << ";";
    }
    cout << *it << endl;
// 7. Print the elements of A on the standard output separated by semicolons. Make sure that
// you do not print a semicolon after the last element.

    return 0;
}