/*
CH-231-A
a7_p1a.cpp
Yen Ling Wong
ywong@jacobs-university.de
Quicksort with Lomoto Partition
*/

#include <iostream>
#include <math.h>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;
using chrono::high_resolution_clock;
using chrono::duration_cast;
using chrono::nanoseconds;

// This file is to combine the results of all quick sorts such that they sort the same arrays

int* random_number_generator() {
    int* arr = new int[10000];
    random_device rd;
    mt19937::result_type seed = rd() ^ (
            (mt19937::result_type)
            chrono::duration_cast<std::chrono::seconds>(
            chrono::system_clock::now().time_since_epoch()
                ).count() +
            (mt19937::result_type)
            chrono::duration_cast<std::chrono::microseconds>(
                chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    mt19937 gen(seed);
    uniform_int_distribution<unsigned> distrib(1, 999999999);

    for( long long int i = 0; i < 10000; ++i ) {
        // And here
        arr[i] = distrib(gen);
    }
    return arr;
}

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

    int size = 10000;

    double total_time_lomoto = 0;
    double total_time_hoare = 0;
    double total_time_median = 0;

    for (int i = 0; i < 100000; i++) {
        int* array1 = random_number_generator();
        int* array2 = new int[size];
        int* array3 = new int[size];

        for (int i = 0; i < size; i++) {
            array2[i] = array1[i];
            array3[i] = array1[i];
        }

        auto start1 = high_resolution_clock::now();
        lomoto_quick_sort(array1, 0, size - 1);
        auto end1 = high_resolution_clock::now();
        auto time1 = duration_cast<nanoseconds>(end1 - start1).count();

        auto start2 = high_resolution_clock::now();
        hoare_quick_sort(array2, 0, size - 1);
        auto end2 = high_resolution_clock::now();
        auto time2 = duration_cast<nanoseconds>(end2 - start2).count();

        auto start3 = high_resolution_clock::now();
        median_quick_sort(array3, 0, size - 1);
        auto end3 = high_resolution_clock::now();
        auto time3 = duration_cast<nanoseconds>(end3 - start3).count();

        total_time_lomoto += time1;
        total_time_hoare += time2;
        total_time_median += time3;

        delete[] array1;
        delete[] array2;
        delete[] array3;

    }

    double average_time_lomoto = total_time_lomoto / 100000;
    double average_time_hoare = total_time_hoare / 100000;
    double average_time_median = total_time_median / 100000;

    ofstream myfile;
    myfile.open("example.txt" , ios::app);
    myfile << "Average running time for Lomoto Quick Sort is " << average_time_lomoto / pow(10, 8) << "." << endl;
    myfile << "Average running time for Hoare Quick Sort is " << average_time_hoare / pow(10, 8) << "." << endl;
    myfile << "Average running time for Median of Three Quick Sort is " <<  average_time_median / pow(10, 8) << "." << endl;
    myfile.close();

    return 0;
}