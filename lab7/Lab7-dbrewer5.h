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
std::vector<double> bubbleSort(std::vector<double> v);
std::vector<double> insertionSort(std::vector<double> v);
std::vector<double> selectionSort(std::vector<double> v);
std::vector<double> mergeSort(std::vector<double> v);
std::vector<double> quickSort(std::vector<double> v);

#endif
