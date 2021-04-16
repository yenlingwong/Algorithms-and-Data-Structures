/*
CH-231-A
a2_p5.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
#include <set>
#include <time.h>

using namespace std;

int main() {
    set<int> s;
// Use a suitable STL container that 
// supports the needed operations and corresponding iterators for all actions.
    int entry = 0;
    srand(time(0));
// Make sure that you initialize the random number generator with the local time of your
// system at the beginning of your program.
    while(1) {
        int lot = rand() % 49 + 1;
        auto ret = s.emplace(lot);
        if (ret.second) {
            entry++;
// add the drawn number to a container that stores all drawn
// numbers (but make sure that your container will not contain duplicates).
        }
        if (entry == 6) {
            break;
        }
    }
//  Draw six different numbers using the formula rand() % 49 + 1.

    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << " ";
    }
// print them on the standard output in ascending order.
    
    return 0;
}
