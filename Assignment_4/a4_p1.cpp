/*
CH-231-A
a4_p1.cpp
Yen Ling Wong
ywong@jacobs-university.de
*/

#include <random>     // mt19937 and uniform_int_distribution
#include <algorithm>  // reverse
#include <iostream>   // cout
#include <chrono> // Time
#include <vector>
#include <ctime>
#include <fstream> // Write into file
#include <math.h> // Pow

using namespace std;
using chrono::high_resolution_clock;
using chrono::duration_cast;
using chrono::nanoseconds;

int* random_number_generator() {
    int* randl = new int[10000000]; 
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10000000; i++) {
        int rand_number = (rand() % 5000000) + 1;
        randl[i] = rand_number;
    }
    return randl;
}
// Random Number Generator

void insertion_sort(int* array, int left, int right) {
    for (int i = left; i <= right; i++) {
        int temp = array[i];
        int j = i;
        while ((j > left) && (array[j - 1] > temp)) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = temp;
    }
}

void merge(int* arr, int* temp, int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;
    while ((i <= mid) && (j <= right)){
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    for (; j <= right; j++, k++)
        temp[k] = arr[j];

    for (; i <= mid; i++, k++)
        temp[k] = arr[i];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}
// Merge elements one level up

void merge_sort(int* arr, int* temp, int left, int right, int threshold) {
    if (left < right) {
        // If there is more than one element in the array
        if ((right - left) <= threshold)
        // Threshold represents k value
        // When a subarray has length k
        // Perform insertion sort
            insertion_sort(arr, left, right);
        else {
            int mid = (left + right) / 2;
            merge_sort(arr, temp, left, mid, threshold);
            // Recursive call
            merge_sort(arr, temp, mid + 1, right, threshold);
            merge(arr, temp, left, mid, right);
        }
    }
}
// Merge Sort Algorithm

void print_array(int* A, int size) {
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    int k = 200;
    // Change value of k manually here
    int* temp = new int[10000000];
    int* list1 = random_number_generator();
    int* list2 = random_number_generator();
    int* list3 = random_number_generator();
    int* list4 = random_number_generator();
    // Creating 4 lists for average

    auto start1 = high_resolution_clock::now();
    merge_sort(list1, temp, 0, 9999999 ,k);
    auto end1 = high_resolution_clock::now();
    auto start2 = high_resolution_clock::now();
    merge_sort(list2, temp, 0, 9999999 ,k);
    auto end2 = high_resolution_clock::now();
    auto start3 = high_resolution_clock::now();
    merge_sort(list3, temp, 0, 9999999 ,k);
    auto end3 = high_resolution_clock::now();
    auto start4 = high_resolution_clock::now();
    merge_sort(list4, temp, 0, 9999999 ,k);
    auto end4 = high_resolution_clock::now();

    auto time1 = duration_cast<nanoseconds>(end1 - start1).count();
    auto time2 = duration_cast<nanoseconds>(end2 - start2).count();
    auto time3 = duration_cast<nanoseconds>(end3 - start3).count();
    auto time4 = duration_cast<nanoseconds>(end4 - start4).count();

    auto averagetime = (time1 + time2 + time3 + time4) / 4 ;

    start1 = high_resolution_clock::now();
    merge_sort(list1, temp, 0, 9999999 ,k);
    end1 = high_resolution_clock::now();
    start2 = high_resolution_clock::now();
    merge_sort(list2, temp, 0, 9999999 ,k);
    end2 = high_resolution_clock::now();
    start3 = high_resolution_clock::now();
    merge_sort(list3, temp, 0, 9999999 ,k);
    end3 = high_resolution_clock::now();
    start4 = high_resolution_clock::now();
    merge_sort(list4, temp, 0, 9999999 ,k);
    end4 = high_resolution_clock::now();
    // All lists are already merged for best case

    time1 = duration_cast<nanoseconds>(end1 - start1).count();
    time2 = duration_cast<nanoseconds>(end2 - start2).count();
    time3 = duration_cast<nanoseconds>(end3 - start3).count();
    time4 = duration_cast<nanoseconds>(end4 - start4).count();

    auto besttime = (time1 + time2 + time3 + time4) / 4 ;

    reverse(list1, list1 + 10000000);
    reverse(list2, list2 + 10000000);
    reverse(list3, list3 + 10000000);
    reverse(list4, list4 + 10000000);
    // Reverse list for worst case

    start1 = high_resolution_clock::now();
    merge_sort(list1, temp, 0, 9999999 ,k);
    end1 = high_resolution_clock::now();
    start2 = high_resolution_clock::now();
    merge_sort(list2, temp, 0, 9999999 ,k);
    end2 = high_resolution_clock::now();
    start3 = high_resolution_clock::now();
    merge_sort(list3, temp, 0, 9999999 ,k);
    end3 = high_resolution_clock::now();
    start4 = high_resolution_clock::now();
    merge_sort(list4, temp, 0, 9999999 ,k);
    end4 = high_resolution_clock::now();

    time1 = duration_cast<nanoseconds>(end1 - start1).count();
    time2 = duration_cast<nanoseconds>(end2 - start2).count();
    time3 = duration_cast<nanoseconds>(end3 - start3).count();
    time4 = duration_cast<nanoseconds>(end4 - start4).count();

    auto worsttime = (time1 + time2 + time3 + time4) / 4 ;

    delete[] temp;

    ofstream myfile;
    myfile.open("example.txt", ios_base::app);
    myfile << k << " ";
    myfile << averagetime/pow(10, 9) << " ";
    myfile << besttime/pow(10, 9) << " ";
    myfile << worsttime/pow(10, 9) << endl;
    // Writing into text file

    return 0;
}