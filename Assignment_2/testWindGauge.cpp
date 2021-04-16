/*
CH-231-A
a2_p3.cpp
Yen Ling Wong
y.wong@jacobs-university.de
*/

#include <iostream>
#include <deque>
#include "WindGauge.h"

using namespace std;

int main() {
    WindGauge w;
// 1. Create a WindGauge object.

    w.currentWindSpeed(15);
    w.currentWindSpeed(16);
    w.currentWindSpeed(12);
    w.currentWindSpeed(15);
    w.currentWindSpeed(15);
    w.dump();
// 2. Add five wind speeds: 15, 16, 12, 15, and 15, and then dump the gauge

    w.currentWindSpeed(16);
    w.currentWindSpeed(17);
    w.currentWindSpeed(16);
    w.currentWindSpeed(16);
    w.currentWindSpeed(20);
    w.currentWindSpeed(17);
    w.currentWindSpeed(16);
    w.currentWindSpeed(15);
    w.currentWindSpeed(16);
    w.currentWindSpeed(20);
    w.dump();
// 3. Add ten more measurements: 16, 17, 16, 16, 20, 17, 16, 15, 16, and 20 (bringing the total to
// over 12) and dump the numbers again.

    cout << w.getnum_of_entries() << endl;

    return 0;
}
