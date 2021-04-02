/*
CH-231-A
a7_p2a.cpp
Yen Ling Wong
ywong@jacobs-university.de
Dual Pivot Quicksort
*/

// Reference: https://ide.geeksforgeeks.org/svXGDPDYfy

#include <iostream>

using namespace std;

void print_array(int* array, int size){
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void swap(int * a, int * b) {
  int temp = * a;
  * a = * b;
  * b = temp;
}

void sort(int array[], int low, int high) {
      if (high <= low) {
        // If there is only one element in subarray
        return;
      }
      if (array[low] > array[high]) {
        swap(array[low], array[high]);
      }
      int pivot1 = array[low];
      int pivot2 = array[high];

      int lt = low + 1;
      int gt = high - 1;
      int i = low + 1;
      // This acts as cursor

      while (i <= gt) {
          if (array[i] < pivot1) {
            swap(array[i], array[lt]);
            lt++;
            i++;
          } else if (array[i] > pivot2) {
            swap(array[i], array[gt]);
            gt--;
          } else {
            i++;
          }
      }
      // Sort Elements less than first pivot to the left of the first pivot
      // Sort Elements more than second pivot to the right of second pivot
      // Until i collides with gt

      swap(array[low], array[lt - 1]);
      swap(array[gt + 1], array[high]);

      lt--;
      gt++;
      // lt and gt are the points where the array is partitioned

      sort(array, low, lt - 1);
      sort(array, lt + 1, gt - 1);
      sort(array, gt + 1, high);
}

int main() {
    int array[8] = {24, 8, 42, 75, 29, 77, 38, 57};
    int size = sizeof(array)/sizeof(array[0]);
    sort(array, 0, size - 1);
    print_array(array, size);
    return 0;
}
