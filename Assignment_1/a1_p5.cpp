/*
CH-231-A
a1_p5.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

int main() {
    vector<string> word_vector;
    string word;
    string quit = "END";

    while(1) {
        cout << "Please enter a word." << endl;
        getline(cin, word);
        if (word == quit) {
            break;
        } else {
            word_vector.push_back(word);
        }
    }

    if (word_vector.size() >= 5) {
        string temp = word_vector.at(1);
        word_vector.at(1) = word_vector.at(4);
        word_vector.at(4) = temp;
    } else if (word_vector.size() >= 2) {
        cout << "Fifth element does not exist" << endl;
    } else {
        cout << "Both elements do not exist" << endl;
    }

    word_vector.at(word_vector.size() - 1) = "???";

    for (unsigned int i = 0; i < word_vector.size() - 1; i++) {
        cout << word_vector[i] << "," ;
    }
    cout << word_vector.at(word_vector.size() - 1) << endl;

    vector<int>::iterator it;
    for (auto it = word_vector.begin(); it != word_vector.end() - 1; it++) {
        cout << *it << ";";
    }
    cout << word_vector.at(word_vector.size() - 1) << endl;

    // reverse(word_vector.begin(), word_vector.end());
    for (auto it = word_vector.rbegin(); it != word_vector.rend(); it++) {
        cout << *it << " ";
    }
    return 0;
}
// TA's comments: p5: Great but use reverse iterator next time (fixed) total : 1 Make sure to comment next time even if its small program
