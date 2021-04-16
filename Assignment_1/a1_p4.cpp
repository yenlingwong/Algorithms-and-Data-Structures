/*
CH-231-A
a1_p4.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> str_vector;
    string word;
    string quit = "END";

    while(1) {
        cout << "Please enter a word." << endl;
        cin >> word;
        if (word == quit) {
            break;
        } else {
            str_vector.push_back(word);
        }    
    }

    for (unsigned int i = 0; i < str_vector.size(); i++) {
        cout << str_vector[i] << " " ;
    }

    cout << endl;

    vector<int>::iterator it;
    for (auto it = str_vector.begin(); it != str_vector.end() - 1; it++) {
        cout << *it << " , ";
    }
    cout << str_vector.at(str_vector.size() - 1);

    return 0;
}
// TA's comments: 1.9 p4: Excellent total : 1
