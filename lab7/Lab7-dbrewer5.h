/*
  Date: 11/15/18
  Name: Devin Brewer
  Desc: COSC_2030 Lab #7; Implementing Sorts
        Lab7-dbrewer5.h
*/

#ifndef LAB7_DBREWER5_H
#define LAB7_DBREWER5_H

#include <vector>

// Define all the sorting algorithms to be implemented
std::vector<int> bubbleSort(std::vector<int> v);
std::vector<int> insertionSort(std::vector<int> v);
std::vector<int> selectionSort(std::vector<int> v);
std::vector<int> mergeSort(std::vector<int> v);
std::vector<int> quickSort(std::vector<int> v);

#endif
