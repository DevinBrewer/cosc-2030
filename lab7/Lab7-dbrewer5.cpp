/*
  Date: 11/15/18
  Name: Devin Brewer
  Desc: COSC_2030 Lab #7; Implementing Sorts
        Lab7-dbrewer5.cpp // Driver
*/


#include "Lab7-dbrewer5.h"  // Local header file
#include "winTimer.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

/* ---Methods--- */
vector<int> fillRandom(int n, int min, int max, int seed) {
  srand(seed);
  vector<int> v;

  for (int i = 0; i < n; i++) {
    v.push_back((rand() % max) + min);  // Add a random number to the vector
  }

  return v;
}

vector<int> bubbleSort(vector<int> v) {
  // Worst case ~ O(n^2) comparisons, swaps
  // BEst case ~ O(n) comparisions, O(1) swaps
  for (int n = v.size(); n > 0; n--) {
    for (int i = 0; i < n-1; i++) {
      if (v.at(i) > v.at(i+1)) {
        // Swap
        int temp = v.at(i);
        v.at(i) = v.at(i+1);
        v.at(i+1) = temp;
      }
    }
  }

  return v;
}

vector<int> insertionSort(vector<int> v) {
  // Worst case ~ O(n^2) comparisions, swaps
  // Best case ~ O(n) comparisions, O(1) swaps
  for (int i = 1; i < v.size(); i++) {
    for (int j = i; (j > 0 && v.at(j-1) > v.at(j)); j--) {
      // Swap
      int temp = v.at(j);
      v.at(j) = v.at(j-1);
      v.at(j-1) = temp;
    }
  }

  return v;
}

vector<int> selectionSort(vector<int> v) {
  // Worst case ~ O(n^2) comparisons, O(n) swaps
  // Best case ~ O(n^2) comparisons, O(n) swaps
  for (int j = 0; j < v.size()-1; j++) {
    int imin = j;
    for (int i = j+1; i < v.size(); i++) {
      // check and see if a smaller value exists
      if (v.at(i) < v.at(imin)) {
        // New min found
        imin = i;
      }
    }

    if (imin != j) {
      // swap
      int temp = v.at(j);
      v.at(j) = v.at(imin);
      v.at(imin) = temp;
    }
  }

  return v;
}

vector<int> mergeSort(vector<int> v) {
  // Recursive Top-down
  // Worst case O(n log n)
  // Best case O(n log n)

  // Base case
  if (v.size() <= 1) {
    return v;
  }

  // Divide the list into two different sublists
  vector<int> left;
  vector<int> right;

  for (int i = 0; i < v.size(); i++) {
    // Place first half in left; remainder in right
    if (i < (v.size()/2)) {
      left.push_back(v.at(i));
    } else {
      right.push_back(v.at(i));
    }
  }

  // Recursively sort both sublists
  left = mergeSort(left);
  right = mergeSort(right);

  // Merge the now sorted sublists
  return merge(left, right);
}

vector<int> merge(vector<int> left, vector<int> right) {
  vector<int> result;

  // Merge the two lists till one is empty
  while (left.size() != 0 && right.size() != 0) {
      if (left.front() <= right.front()) {
        result.push_back(left.front());
        left.erase(left.begin());
      } else {
        result.push_back(right.front());
        right.erase(right.begin());
      }
  }

  // Consume the remaining list
  while (left.size() != 0) {
    result.push_back(left.front());
    left.erase(left.begin());
  }
  while (right.size() != 0) {
    result.push_back(right.front());
    right.erase(right.begin());
  }

  return result;
}

void quickSort(int arr[], int lo, int hi) {
  // Lomuto partition scheme
  // Worst case O(n^2)
  // Best case O(n log n)

  if (lo < hi) {
    int pi = partition(arr, lo, hi);
    quickSort(arr, lo, pi-1);
    quickSort(arr, pi+1, hi);
  }
}

int partition(int arr[], int lo, int hi) {
  int pivot = arr[hi];
  int i = lo - 1;

  for (int j = lo; j <= hi-1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[hi]);
  return (i+1);
}

void swap(int* i, int* j) {
  int t = *i;
  *i = *j;
  *j = t;
}

// Return whether a vector is sorted lowest to highest
bool isSorted(vector<int> v) {
  for (int i = 0; i < v.size()-1; i++) {
    if (v.at(i) > v.at(i+1)) {
      return false;
    }
  }
  return true;
}

int main() {
  cout << "Enter a seed: ";
  int seed = 0;
  cin >> seed;

  /*  ----Bubble Sort----  */
  // vector<int> bubbleV = fillRandom(10100, 1, 500, seed);   // ~4 Sec
  // vector<int> bubbleV = fillRandom(20200, 1, 500, seed);   // ~15 Sec
  // vector<int> bubbleV = fillRandom(40400, 1, 500, seed);   // ~63 Sec

  // Timer time;
  // time.start();
  // bubbleV = bubbleSort(bubbleV);
  // time.stop();
  // cout << "Sorted in: " << time() << endl;

  /*  ----Insertion Sort----  */
  // vector<int> insertionV = fillRandom(12000, 1, 500, seed);  // ~4 Sec
  // vector<int> insertionV = fillRandom(24000, 1, 500, seed);  // ~16 Sec
  // vector<int> insertionV = fillRandom(48000, 1, 500, seed);  // ~65 Sec

  // Timer time;
  // time.start();
  // insertionV = insertionSort(insertionV);
  // time.stop();
  // cout << "Sorted in: " << time() << endl;

  /*  ----Selection Sort----  */
  // vector<int> selectionV = fillRandom(13000, 1, 500, seed);  // ~4 Sec
  // vector<int> selectionV = fillRandom(26000, 1, 500, seed);  // ~16 Sec
  // vector<int> selectionV = fillRandom(52000, 1, 500, seed);  // ~66 Sec

  // Timer time;
  // time.start();
  // selectionV = selectionSort(selectionV);
  // time.stop();
  // cout << "Sorted in: " << time() << endl;

  /*  ----Merge Sort----  */
  // vector<int> mergeV = fillRandom(250000, 1, 500, seed);   // ~4 Sec
  // vector<int> mergeV = fillRandom(500000, 1, 500, seed);   // ~13 Sec
  // vector<int> mergeV = fillRandom(1000000, 1, 500, seed);  // ~47 Sec

  // Timer time;
  // time.start();
  // mergeV = mergeSort(mergeV);
  // time.stop();
  // cout << "Sorted in: " << time() << endl;

  /*  ----Quick Sort---- */
  // vector<int> quickV = fillRandom(1000000, 1, 500, seed);   // ~4 Sec
  // vector<int> quickV = fillRandom(2000000, 1, 500, seed);   // ~15 Sec
  // vector<int> quickV = fillRandom(4000000, 1, 500, seed);   // ~62 Sec

  // Convert the vector to an array to use the quickSort() algorithm
  // int* arr = quickV.data();
  // int n = quickV.size();

  // Timer time;
  // time.start();
  // quickSort(arr, 0, n-1);
  // time.stop();
  // cout << "Sorted in: " << time() << endl;


  /*  ----STL::Sort----  */
  // vector<int> stlV = fillRandom(40000000, 1, 500, seed);   // ~4 Sec
  // vector<int> stlV = fillRandom(80000000, 1, 500, seed);   // ~8 Sec
  // vector<int> stlV = fillRandom(160000000, 1, 500, seed);  // ~16 Sec

  // Timer time;
  // time.start();
  // sort(stlV.begin(), stlV.end());
  // time.stop();
  // cout << "Sorted in: " << time() << endl;
}
