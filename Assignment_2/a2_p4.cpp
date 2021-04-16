/*
CH-231-A
a2_p4.cpp
Yen Ling Wong
y.wong@jacobs-university.de
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    for (int i = 1; i < 31; i++) {
        v.push_back(i);
    }
// Write a program which fills a vector with the integer values from 1 to 30. 

    v.push_back(5);
// Then add the value 5 at the end of the vector. 
    reverse(v.begin(), v.end());
// Reverse the vector using the reverse() function from the algorithm library

    vector<int>::iterator ite;
    for (ite = v.begin(); ite != v.end(); ite++) {
        cout << *ite << " ";
    }
    cout << endl;
// print the content of the vector on the standard output using an iterator.

    replace(v.begin(), v.end(), 5, 129);
// Then replace all occurrences of the value 5 by the value 129 
// using the replace() function from the algorithm library

    for (ite = v.begin(); ite != v.end(); ite++) {
        cout << *ite << " ";
    }
//  print the modified vector again on the standard output.
    return 0;
}
