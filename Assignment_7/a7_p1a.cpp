/*
CH-231-A
a7_p1a.cpp
Yen Ling Wong
ywong@jacobs-university.de
Quicksort with Lomoto Partition
*/

#include <iostream>

using namespace std;

int lomoto_partition(int array[], int low, int high) {
    int pivot = array[high];
    int x = low - 1;

    for (int i = low; i <= high - 1; i++) {
        if (array[i] <= pivot) {
            x++;
            swap(array[x], array[i]);
        }
    }
    swap(array[x + 1], array[high]);
    return (x + 1);
}

void lomoto_quick_sort(int array[], int low, int high) {
    if (low < high) {
        int divider = lomoto_partition(array, low, high);
        lomoto_quick_sort(array, low, divider - 1);
        lomoto_quick_sort(array, divider + 1, high);
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
    lomoto_quick_sort(array, 0, size - 1);
    print_array(array, size);
    return 0;
}
// Reference: https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/?ref=rp
 