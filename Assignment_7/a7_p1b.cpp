/*
CH-231-A
a7_p1b.cpp
Yen Ling Wong
ywong@jacobs-university.de
Quicksort with Hoare Partition
*/

#include <iostream>

using namespace std;

int hoare_partition(int array[], int low, int high) {
    int pivot = array[low];
    int x = low - 1;
    int y = high + 1;

    while(true) {
        do {
            x++;
        } while(array[x] < pivot);
            
        do {
            y--;
        } while(array[y] > pivot);
            
        if (x >= y) {
            return y;
        }
        swap(array[x], array[y]);
    }
}

void hoare_quick_sort(int array[], int low, int high) {
    if (low < high) {
        int divider = hoare_partition(array, low, high);
        hoare_quick_sort(array, low, divider);
        hoare_quick_sort(array, divider + 1, high);
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[10] = {2, 9, 1, 6, 3, 7, 8, 10, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    hoare_quick_sort(array, 0, size - 1);
    print_array(array, size);
    return 0;
}
// Reference: https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/?ref=rp