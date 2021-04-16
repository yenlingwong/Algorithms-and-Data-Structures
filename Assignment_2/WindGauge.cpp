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

WindGauge::WindGauge(int period) {
    this->num_of_entries = 0;
    this->period = period;
    cout << "A WindGauge object has been created." << endl;
}

void WindGauge::currentWindSpeed(int speed) {
    if (num_of_entries < period) {
        this->deque_windspeed.push_back(speed);
        this->num_of_entries++;
//  When currentWindSpeed() is called, the current wind speed is added to the history
    } else { 
        this->deque_windspeed.pop_front();
        this->deque_windspeed.push_back(speed);
    }
//  If the history is then longer than the specified period, the oldest wind speed is discarded.
    cout << "A new speed has been added." << endl;
}

int WindGauge::highest() const {
    int top = this->deque_windspeed[0];
    for (int i = 1; i < this->num_of_entries - 1; i++) {
        if (this->deque_windspeed[i] > top) {
            top = this->deque_windspeed[i];
        }
    }
    return top;
}

int WindGauge::lowest() const {
    int base = this->deque_windspeed[0];
    for (int i = 1; i < this->num_of_entries - 1; i++) {
        if (this->deque_windspeed[i] < base) {
            base = this->deque_windspeed[i];
        }
    }
    return base;
}

int WindGauge::average() const {
    int sum = 0;
    for (int i = 0; i < this->num_of_entries; i++) {
        sum += this->deque_windspeed[i];
    }
    return sum/this->num_of_entries;
}
// The other three functions return the highest, lowest, and average wind speeds reported during
// the history period.

void WindGauge::dump() {
    cout << endl;
    cout << "Highest wind speed: " << this->highest() << endl;
    cout << "Lowest wind speed: " << this->lowest() << endl;
    cout << "Average wind speed: " << this->average() << endl;
    cout << endl;
}
//  write a dump function that prints out the lowest, highest, and average wind speed 

int WindGauge::getnum_of_entries() {
    return this->num_of_entries;
}
