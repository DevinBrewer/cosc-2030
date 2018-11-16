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

vector<int> bubbleSort(vector<int> v) { // Wikipedia::Opimimzing bubble sort
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

vector<int> insertionSort(vector<int> v) { // Wikipedia::Insetion Sort
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
  return v;
}

vector<int> mergeSort(vector<int> v) {
  return v;
}

vector<int> quickSort(vector<int> v) {
  return v;
}

int main() {
  // Test the sorting algorithm
  cout << "Enter the size: ";
  int n = 0;
  cin >> n;

  cout << "Enter a seed: ";
  int seed = 0;
  cin >> seed;

  vector<int> newVector = fillRandom(n, 0, n, seed);

  // Sort the vector
  cout << "Sorting... ";
  newVector = insertionSort(newVector);
  cout << "Done!" << endl;

  // Print the vector
  if (n <= 10) {
    for (vector<int>::const_iterator i = newVector.begin(); i != newVector.end(); ++i) {
      cout << *i << ' ';
    }
  }
}
