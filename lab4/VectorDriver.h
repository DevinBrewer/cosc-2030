/* File: VectorDriver.cpp
 * Athr: Dimitri Zarzhitsky
 * Date: October 16, 2002
 *
 * Desc: provides the basic framework and examples for an introduction to
 *       the STL::vector, iterators, and the algorithms facilities.
 *
 * Edited by: Rafe Cooley
 * Date: October 1, 2017 (the future)
 *
 */
typedef unsigned long ulong;

#include <iostream>
#include <vector>
#include <cstdlib>  // Random
#include <ctime>  // Time for rand()

using std::cout;
using std::endl;
using std::vector;

// fill vector that has pre-allocated space with consecutive numbers
void fill_vector(vector<short> &data) {
  for (ulong i=0; i<data.size(); i++) {
    data.at(i) = i;
  }
}

// print our vector in a fancy way
void print(const vector<short> &data) {
  if (data.empty()) {
    cout << "<empty>";
  } else {
    cout << "<" << data.at(0);
    for (ulong i=1; i<data.size(); i++) {
      cout << ", " << data.at(i);
    }
    cout << ">";
  }
}

// use iterator to sum the elements of a vector
short compute_sum(const vector<short> &data) {
  std::vector<short>::const_iterator iter = data.begin();

  short sum = 0;
  while (iter != data.end()) {
    sum += *iter;
    iter++;
  }

  return sum;
}

// Add 10 random numbers to the end of the vector
void add_numbers(vector<short> &data) {
  // Set the random seed
  srand((unsigned)time(0));

  // Generate the numbers
  for (int i=0; i < 10; i++) {
    data.push_back((short)rand());
  }
}

// Print only the even numbers in the vector
void print_even(vector<short> &data) {
  if (data.empty()) {
    cout << "<empty>";
  } else {
    cout << "<" << data.at(0);
    // Start parsing through every other number and print it out
    for (ulong i = 2; i < data.size(); i+=2) {
      cout << ", " << data.at(i);
    }
    cout << ">";
  }
}

// Check if a "value" is present in the vector
bool is_present(const vector<short> &data, short value) {
  // Create the iterator
  std::vector<short>::const_iterator iter = data.begin();

  // Search for "value"
  while (iter != data.end()) {
    // Check for the value
    if (*iter == value) {
      return true;
    }

    // Increment the iterator
    iter++;
  }

  // "value" wasnt found
  return false;
}
