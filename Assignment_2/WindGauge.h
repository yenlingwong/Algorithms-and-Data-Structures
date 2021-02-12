/*
CH-231-A
a2_p3.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
#include <deque>

using namespace std;

class WindGauge {
    private:
        deque<int> deque_windspeed;
        int num_of_entries;
        int period;
    public:
        WindGauge(int period = 12);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const;
        int average() const;
        void dump();
        int getnum_of_entries();
};