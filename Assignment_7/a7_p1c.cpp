/*
CH-231-A
a7_p1c.cpp
Yen Ling Wong
ywong@jacobs-university.de
Quicksort with Median of 3 Partition
*/

#include <iostream>

using namespace std;

void manual_sort(int array[], int left, int right) {
    int size = right - left + 1;
    if (size <= 1) {
        return ;
    } else if (size == 2) {
        if (array[left] > array[right]) {
            swap(array[left], array[right]);
        }
        return ;
    } else {
        if (array[left] > array[right - 1]) {
            swap(array[left], array[right - 1]);
        }
        if (array[left] > array[right]) {
            swap(array[left], array[right]);
        }
        if (array[right - 1] > array[right]) {
            swap(array[right - 1], array[right]);
        }
    }
}

int median_of_three(int array[], int left, int right) {
    int center = (left + right) / 2;
    if (array[left] > array[center]) {
        swap(array[left], array[center]);
    }
    if (array[left] > array[right]) {
        swap(array[left], array[right]);
    }
    if (array[center] > array[right]) {
        swap(array[center], array[right]);
    }
    swap(array[center], array[right - 1]);
    return array[right - 1];
}

int partition(int array[], int left, int right, double pivot) {
    int leftptr = left;
    int rightptr = right - 1;

    while(true) {
        while(array[++leftptr] < pivot) {
            ;
        }
        while(array[--rightptr] > pivot) {
            ;
        }
        if (leftptr >= rightptr) {
            break;
        } else {
            swap(array[leftptr], array[rightptr]);
        }
    }
    swap(array[leftptr], array[right - 1]);
    return leftptr;
}

void median_quick_sort(int array[], int left, int right) {
    int size = right - left + 1;
    if (size <= 3) {
        manual_sort(array, left, right);
    } else {
        double median = median_of_three(array, left, right);
        int part = partition(array, left, right, median);
        median_quick_sort(array, left, part - 1);
        median_quick_sort(array, part + 1, right);
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int int_array[13] = {2, 9, 1, 6, 3, 7, 8, 10, 4, 5, 100, 99, 99};
    int size = sizeof(int_array) / sizeof(int_array[0]);
    median_quick_sort(int_array, 0, size - 1);
    print_array(int_array, size);
    return 0;
}

// Reference: http://www.java2s.com/Tutorial/Java/0140__Collections/Quicksortwithmedianofthreepartitioning.htm