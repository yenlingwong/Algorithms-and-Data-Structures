/*
CH-231-A
a1_p1.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <iostream>
using namespace std;

template <class T>
class Complex {
    private:
        T real, imaginary;
    public:
        Complex<T>(T real, T imaginary) {
            this -> real = real;
            this -> imaginary = imaginary;
        }
        friend bool operator==(const Complex& c, const Complex& d) {
            return ((c.real == d.real) && (c.imaginary == d.imaginary));
        }
};

template <class T> 
int array_search(T input_array[], int num_of_elements, T to_search) {
    for (int i = 0; i < num_of_elements; i++) {
        if (input_array[i] == to_search) {
            return i;
        } 
    }
    return -1;
}

int main() {
    char char_array[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int int_array[6] = {43, 475, 2, -5, 99, 0};
    double double_array[5] = {24.3, -29992.2, 3.26, 49.2, 880.0};
    float float_array[4] = {23.44467372f, 239.1f, -5.55555f, 234.0f};
    string string_array[3] = {"alpha", "beta", "gamma"};
    Complex<int> complex_array[3] = {Complex <int> (9,8), Complex <int> (7,6), Complex <int> (5,4)};
    Complex<double> complex_darray[3] = {Complex <double> (9.3,8.2), Complex <double> (7.241,-6.234), Complex <double> (5.0,-4.242)};

    if ((array_search(char_array, 7 , 'z') == -1)) {
        cout << "The character is not in the array" << endl;
    } else {
        cout << "The character is in position " << array_search(char_array, 7 , 'z') << endl;
    }

    if ((array_search(int_array, 0, 27) == -1)) {
        cout << "The integer is not in the array" << endl;
    } else {
        cout << "The integer is in position " << array_search(int_array, 6, 0) << endl;
    }

    if ((array_search(double_array, 5, 49.2) == -1)) {
        cout << "The double is not in the array" << endl;
    } else {
        cout << "The double is in position " << array_search(double_array, 5, 49.2) << endl;
    }

    if ((array_search(float_array, 4, 239.1f) == -1)) {
        cout << "The float is not in the array" << endl;
    } else {
        cout << "The float is in position " << array_search(float_array, 4, 239.1f) << endl;
    }

    if ((array_search(string_array, 3, string("epsilon")) == -1)) {
        cout << "The string is not in the array" << endl;
    } else {
        cout << "The string is in position " << array_search(string_array, 3, string("epsilon")) << endl;
    }

    if (array_search(complex_array, 3, Complex <int>(3,-8))) {
        cout << "The integer Complex is not in the array" << endl;
    } else {
        cout << "The integer Complex is in position " << array_search(complex_array, 3, Complex <int>(8,0)) << endl;
    }
    
    if (array_search(complex_darray, 3, Complex <double>(9.3,8.2))) {
        cout << "The double Complex is not in the array" << endl;
    } else {
        cout << "The double Complex is in position " << array_search(complex_darray, 3, Complex <double>(9.3,8.2)) << endl;
    }

    return 0;
}
