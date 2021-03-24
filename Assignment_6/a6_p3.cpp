/*
CH-231-A
a6_p2.cpp
Yen Ling Wong
ywong@jacobs-university.de
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

// This file is to combine the results of both heap sorts such that they sort the same arrays

long long int heapsize = 10000000;
    // Change number of elements here

int* random_number_generator() {
    int* arr = new int[heapsize];
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
    uniform_int_distribution<unsigned> distrib(1, 40000000);

    for( long long int i = 0; i < heapsize; ++i ) {
        // And here
        arr[i] = distrib(gen);
    }
    return arr;
}

void swap(int *x, int *y) {
    int *temp = x;
    x = y;
    y = temp;
}

void heapify(int array[], int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int large = i;
    if (left < n && array[left] > array[i]) {
        large = left;
    }
    if (right < n && array[right] > array[large]) {
        large = right;
    }
    if (large != i) {
        swap(array[i], array[large]);
        heapify(array, n, large);
    }
}
void build_heap(int array[], int n) {
    for (int i = (n/2 - 1); i >= 0; i--) {
        heapify(array, n, i);
    }
}

void heap_sort(int array[], int n) {
    build_heap(array, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void sift_down(int array[], int i, int n) {
   int left = 2 * i + 1;
   int right = 2 * i + 2;
   int large;
   if (right < n && array[right] > array[left]) {
       large = right;
   } else {
       large = left;
   }
   if (large < n && array[large] > array[i]) {
       swap(array[large], array[i]);
       sift_down(array, large, n);
   }
} 

void bottom_up_heap_sort(int array[], int n) {
    build_heap(array, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        sift_down(array, 0, i);
    }
}

void print_array(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

}

int main() {
    int* array1 = random_number_generator();
    int* array2 = random_number_generator();
    int* array3 = random_number_generator();
    int* array4 = random_number_generator();
    int* temp1 = new int[heapsize];
    int* temp2 = new int[heapsize];
    int* temp3 = new int[heapsize];
    int* temp4 = new int[heapsize];

    for (int i = 0; i < heapsize; i++){
        temp1[i] = array1[i];
        temp2[i] = array1[i];
        temp3[i] = array3[i];
        temp4[i] = array4[i];
    }

    auto start1 = high_resolution_clock::now();
    heap_sort(array1, heapsize);
    auto end1 = high_resolution_clock::now();
    auto time1 = duration_cast<nanoseconds>(end1 - start1).count();

    auto start2 = high_resolution_clock::now();
    heap_sort(array2, heapsize);
    auto end2 = high_resolution_clock::now();
    auto time2 = duration_cast<nanoseconds>(end2 - start2).count();

    auto start3 = high_resolution_clock::now();
    heap_sort(array3, heapsize);
    auto end3 = high_resolution_clock::now();
    auto time3 = duration_cast<nanoseconds>(end3 - start3).count();

    auto start4 = high_resolution_clock::now();
    heap_sort(array4, heapsize);
    auto end4 = high_resolution_clock::now();
    auto time4 = duration_cast<nanoseconds>(end4 - start4).count();

    auto start5 = high_resolution_clock::now();
    bottom_up_heap_sort(temp1, heapsize);
    auto end5 = high_resolution_clock::now();
    auto time5 = duration_cast<nanoseconds>(end5 - start5).count();

    auto start6 = high_resolution_clock::now();
    bottom_up_heap_sort(temp2, heapsize);
    auto end6 = high_resolution_clock::now();
    auto time6 = duration_cast<nanoseconds>(end6 - start6).count();

    auto start7 = high_resolution_clock::now();
    bottom_up_heap_sort(temp3, heapsize);
    auto end7 = high_resolution_clock::now();
    auto time7 = duration_cast<nanoseconds>(end7 - start7).count();

    auto start8 = high_resolution_clock::now();
    bottom_up_heap_sort(temp4, heapsize);
    auto end8 = high_resolution_clock::now();
    auto time8 = duration_cast<nanoseconds>(end8 - start8).count();


    ofstream myfile;
    myfile.open("example3.txt", ios_base::app);
    myfile << heapsize << " ";
    myfile << (time1 + time2 + time3 + time4)/4 << " ";
    myfile << (time5 + time6 + time7 + time8)/4 << " " << endl;

    return 0;
}